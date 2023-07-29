import { useEffect, useRef, useState } from "react";
import styles from "./game.module.css";
import {RxExit} from "react-icons/rx";
import { useAuthContext } from "@/auth/AuthContext";
import Player from "@/entities/player.entity";
import {Ball} from "@/entities/ball.entity";
import Link from "next/link";
import {Events} from "@/pages/game/game";
import {Vector2d} from "@/entities/vector2d.entity";


interface IGameProps {
  rival: IUser;
  socket: any;
  gameOver : any;
}

enum Song {
  Hit,
  ScoreWin,
  ScoreLose,
  Win,
  Lose,
  Start,
}

const audioSources: string[] = [
  "/assets/ballBounce.mp3",
  "/assets/scoreWin.mp3",
  "/assets/scoreLose.mp3",
  "/assets/endWin.mp3",
  "/assets/gameOver.mp3",
  "/assets/pongStart.mp3",
];

const PLAYER_MARGINY = 5;
const PLAYER_MOVE_SPEED = 5;
const PLAYER_WIDTH_SCALE = 0.01;
const PLAYER_HEIGTH_SCALE = 0.25;

const SERVER_CANVAS_X = 1920;
const SERVER_CANVAS_Y = 1080;

export default function Game({ rival, socket, gameOver }: IGameProps) {
  const { user } = useAuthContext();
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const scoreboardRef = useRef<HTMLDivElement>(null);
  const containerRef = useRef<HTMLDivElement>(null);

  const [score1, setScore1] = useState(0);
  const [score2, setScore2] = useState(0);
  const [timeInfo, setTimeInfo] = useState("");
  let countDown = 3;
  let gameState : boolean = false;

  let playerTimer : NodeJS.Timer;

  let screenScale : Vector2d;

  const setColor = () => {
    if (containerRef.current) {
      containerRef.current.style.backgroundColor = containerRef.current.style.backgroundColor === 'blue' ? 'pink' : 'blue';
    }
  }

  useEffect(() => {
    let canvas = canvasRef.current as HTMLCanvasElement;
    if (!canvas) return;

    let ctx = canvas.getContext("2d") as CanvasRenderingContext2D;
    if (!ctx) return;

    canvas.width = canvas.clientWidth;
    canvas.height = canvas.clientHeight;


    let timer: NodeJS.Timer;
    let gameTime: number = Date.now() / 1000;

    const ball: Ball = {
      position: {
        X: canvas.width / 2,
        Y: canvas.height / 2,
      },
      speed: {
        X: canvas.width * 0.008,
        Y: canvas.height * 0.008,
      },
      radius: canvas.width * 0.01,
    };

    let player = new Player(
        canvas.width * PLAYER_WIDTH_SCALE,
        canvas.height * PLAYER_HEIGTH_SCALE,
        {
                  X: (canvas.width * PLAYER_WIDTH_SCALE) / 2,
                  Y: canvas.height / 2 - (canvas.height * PLAYER_HEIGTH_SCALE) / 2,
                },
        canvas.height / 2 - (canvas.height * PLAYER_HEIGTH_SCALE) / 2,
        PLAYER_MOVE_SPEED * (canvas.height * 0.0025),
        "lightpink"
    );

    let rival = new Player(
        canvas.width * PLAYER_WIDTH_SCALE,
        canvas.height * PLAYER_HEIGTH_SCALE,
        {
          X: canvas.width - ((canvas.width * PLAYER_WIDTH_SCALE) * 1.5),
          Y: canvas.height / 2 - (canvas.height * PLAYER_HEIGTH_SCALE) / 2,
        },
        canvas.height / 2 - (canvas.height * PLAYER_HEIGTH_SCALE) / 2,
        PLAYER_MOVE_SPEED * (canvas.height * 0.0025),
        "blue"
    );


    let sing: any = [];
    for(let i = 0; i < 6; i++)
      sing[i] = new Audio(audioSources[i]);

    const calculateScreen = (screenPos : Vector2d) : Vector2d => {
      const playerScale : Vector2d = {
        X: 0,
        Y: canvas.height * screenPos.Y / 100,
      };
      return playerScale;
    }

    const calculateBall = (ballPos : Vector2d) : Vector2d => {
      const ret : Vector2d = {
        X: ballPos.X / screenScale.X,
        Y: ballPos.Y / screenScale.Y,
      }
      return ret;
    }

    const calculateScale = () : Vector2d => {
      return {
        X: SERVER_CANVAS_X / canvas.width,
        Y: SERVER_CANVAS_Y / canvas.height,
      }
    }

    screenScale = calculateScale();

    const onResize = (event: Event) => {
      const oldHeight = canvas.height;

      canvas.width = canvas.offsetWidth;
      canvas.height = canvas.offsetHeight;
      const scale = player.position.Y  * 100 / oldHeight;

      player.height = canvas.height * PLAYER_HEIGTH_SCALE;
      player.width = canvas.width * PLAYER_WIDTH_SCALE;
      player.speed = PLAYER_MOVE_SPEED * (canvas.height * 0.0025);
      player.position.X = (canvas.width * PLAYER_WIDTH_SCALE) / 2;
      player.position.Y = scale * canvas.height / 100;
      player.target = player.position.Y;


      rival.height = canvas.height * PLAYER_HEIGTH_SCALE;
      rival.width = canvas.width * PLAYER_WIDTH_SCALE;
      rival.position.X = canvas.width - ((canvas.width * PLAYER_WIDTH_SCALE) * 1.5);
      rival.position.Y = scale * canvas.height / 100;


      ball.radius = canvas.width * 0.01;

      screenScale = calculateScale();
    };

    const onKeyDown = (e: KeyboardEvent) => {
      if (e.key == 'w') {
        player.moveUp();
      } else if (e.key == 's') {
        player.moveDown();
      }
    };

    const onKeyUp = (e: KeyboardEvent) => {
      if (e.key === "w" || e.key === "s") {
        player.speed = PLAYER_MOVE_SPEED * (canvas.height * 0.0025);
        player.target = player.position.Y;
        player.key = 0;
      }
    };

    const updatePlayer = async () => {
      const pos : Vector2d = {
        X: player.position.X * screenScale.X,
        Y: player.position.Y * 100 / canvas.height,
      }
      socket.emit(Events.update, pos);
    }

    socket.on(Events.game, (data : any) => {
        const rivalPos = data.rival;
        const  res = calculateScreen(rivalPos);
        rival.position.Y = res.Y;

        const ballPos = data.ballPos;
        ball.position = calculateBall(ballPos);
        onBallMove(ball.position);
    });

    socket.on(Events.score, (data : any) => {
      console.log(data);
      setScore1(data[0]);
      setScore2(data[1]);
    });

    socket.on(Events.sound, (data : any) => {
      playSound(data);
    });

    socket.on(Events.finish, (data : any) => {
      console.log("finish");
      clearInterval(playerTimer);
      if(data[1] < 0)
        gameOver({state: true, score: data[0], message: "Rakip Oyundan Ayrıldı"});
      else if(data[0] > data[1]) {
        gameOver({state: true, score: data[0], message: "You Win!"});
        playSound(Song.Win);
      }
      else {
        gameOver({state: true, score: data[0], message: "You Lose!"});
        playSound(Song.Lose);
      }
    })

    let hitTime = Date.now();
    const onBallMove = (ballPos : Vector2d) => {
      if(hitTime < Date.now() &&
          ballPos.X - ball.radius < player.position.X + player.width && ballPos.Y >= player.position.Y && ballPos.Y <= player.position.Y + player.height) {
        console.log("Hit");
        hitTime = Date.now() + 1000;
        socket.emit(Events.hit);
        playSound(Song.Hit);
      }
    }
    const gameLoop = async () => {
      ctx.clearRect(0, 0, canvas.width, canvas.height);

      drawBall();
      drawPlayer(player);
      drawRival();

      if(!gameState) {
        drawText();
        return;
      }

      //moveBall();
      player.move();
      movePlayer(player);

    };


    const movePlayer = async (player: Player) => {
      const speed = player.speed;
      if (player.position.Y < player.target) {
        if (
          player.position.Y + player.height + speed <
          canvas.height - PLAYER_MARGINY
        )
          player.position.Y += speed;
        else if (
          player.position.Y + player.height <
          canvas.height - PLAYER_MARGINY
        )
          player.position.Y += 1;
      } else if (player.position.Y > player.target) {
        if (player.position.Y - speed > PLAYER_MARGINY)
          player.position.Y -= speed;
        else if (player.position.Y > PLAYER_MARGINY) player.position.Y -= 1;
      }
    };

    const drawPlayer = (player: Player) => {
      ctx.fillStyle = player.color;
      ctx.fillRect(
        player.position.X,
        player.position.Y,
        player.width,
        player.height
      );
    };

    const drawRival = () => {
      ctx.fillStyle = "blue";
      ctx.fillRect(
          rival.position.X,
          rival.position.Y,
          rival.width,
          rival.height,
      );
    }

    const playSound = async (index : number) => {
      sing[index].play();
    }

    const drawBall = () => {
      ctx.beginPath();
      ctx.arc(ball.position.X, ball.position.Y, ball.radius, 0, Math.PI * 2);
      ctx.fillStyle = "#00BFFF";
      ctx.fill();
      ctx.closePath();
    };

    const drawText = () => {
      ctx.font =   canvas.width * 0.10 + 'px Arial';
      ctx.fillStyle = 'green';
      ctx.textAlign = 'center';
      ctx.fillText(countDown > 0 ? countDown.toString() : "F I G H T  !", canvas.width / 2, canvas.height / 2);
    }

    const startGame = ()  => {
      playSound(Song.Start);
      const backTime = setInterval(() => {
        if(countDown == 0) {
          gameState = true;
          clearInterval(backTime);
        }
        countDown--;
      }, 1000);
    }

    timer = setInterval(() => {
      const time = Date.now() / 1000;
      const min = Math.floor((time - gameTime) / 60);
      const sec = Math.floor(time - (gameTime + min * 60));
      setTimeInfo(
        min.toString().padStart(2, "0") + ":" + sec.toString().padStart(2, "0")
      );
    });


    startGame();
    setInterval(gameLoop, 30);
    playerTimer = setInterval(updatePlayer, 50);

    window.addEventListener("keydown", onKeyDown);
    window.addEventListener("keyup", onKeyUp);
    window.addEventListener("resize", onResize);

    return () => {
      clearInterval(timer);
      socket.disconnect();
      socket.close();
    };
  }, []);

  return (
      <div className={styles.container} ref={containerRef}>
        <div className={styles.scoreboard} ref={scoreboardRef}>
          <div className={styles.playerScore}>
            <img src={user?.avatar || ""} className={styles.avatar} />
            <div className={styles.playerInfo}>
              <span className={styles.username}>{user?.full_name}</span>
              <span className={styles.score}>{score1}</span>
            </div>
          </div>
          <div className={styles.timer}>{timeInfo}</div>
          <div className={styles.playerScore}>
            <div className={styles.playerInfo}>
              <span className={styles.score}>{score2}</span>
              <span className={styles.username}>{rival?.full_name}</span>
            </div>
            <img src={rival?.avatar || ""} className={styles.avatar} />
          </div>
        </div>
        <div className={styles.game}>
          <canvas className={styles.canvas} ref={canvasRef}></canvas>
        </div>
        <div className={styles.footer}>
          Exit
          <Link href={"/"}><RxExit/></Link>
        </div>
        <button className={styles.footer2} onClick={setColor}>
          Color
        </button>
      </div>
  );
}


import {ReactNode, useEffect, useRef, useState} from "react";
import DashboardLayout from "@/layouts/DashboardLayout";
import Matching from "@/sections/game/matching";
import FinishGame from "@/sections/game/finish-game";
import Game from "@/sections/game/game";
import { gameSocket } from "@/api/socket/game";
import { useAuthContext } from "@/auth/AuthContext";
import {useRouter} from "next/router";

export enum Events {
  connect = "connect",
  disconnect = "disconnect",
  start = "client:startGame",
  finish = "client:finishGame",
  match = "server:match",
  update = "server:updatePlayer",
  game = "client:updateGame",
  score = "client:setScore",
  sound = "client:playSound",
  hit = "server:hit",
}

GamePage.getLayout = (page: any) => <DashboardLayout isHidden={true}>{page}</DashboardLayout>

export default function GamePage() {
  const { user } = useAuthContext();

  const [rival, setRival] = useState<IUser>();

  const [pending, setPending] = useState(true);

  const [gameOver, setGameOver] = useState(false);

  const [score, setScore] = useState(0);

  const [message, setMessage] = useState("");


  const router = useRouter();

  let socket: any = useRef<any>(null);

  const finishGame = (val : any) => {
    setScore(val.score);
    setMessage(val.message);
    setGameOver(val.state);
  }

  useEffect(() => {
    if (!user) return;
    console.log("2");

    socket.current = gameSocket();



    //Debug
    socket.current.on(Events.connect, () => {
      console.log("connect");
    });


   const code = router.query.invite;
   socket.current.emit(Events.match, { id: user!.id , invite: code});

    socket.current.on(Events.start, (rival: any) => {
      setPending(false);
      setGameOver(false);
      setRival(rival);
    });

    /*
    socket.current.on(Events.finish, () => {
      setPending(false);
      setGameOver(true);
    });
     */


    socket.current.on(Events.disconnect, () => {
      setPending(false);
      setGameOver(true);
    });

    return () => {
      socket.current.disconnect();
    };
  }, []);

  if (pending) {
    return <Matching invite={router.query.invite}/>;
  }

  if (gameOver) {
    return <FinishGame score={score} message={message} />;
  }

  if (rival) {
    return <Game rival={rival} socket={socket.current} gameOver={finishGame} />;
  }
}

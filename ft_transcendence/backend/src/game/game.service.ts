import {Injectable} from '@nestjs/common';
import {Server, Socket} from 'socket.io';
import {UserService} from 'src/user/user.service';
import {CacheService} from 'src/cache/cache.service';
import {User} from 'src/user/user.entity';
import Room from './entities/room.entity';
import {Game, GameStatus, Vector2} from './entities/game.entity';
import {MatchService} from "../match/match.service";

export interface GameRoom {
  user: User;
  score: number;
  rivalRoomId: string;
}

const ROOM_PREFIX = 'R-';
const GAME_PREFIX = 'G-';

@Injectable()
export class GameService {
  private readonly SCREEN_WIDTH: number = 1920;
  private readonly SCREEN_HEIGTH: number = 1080;
  private BALL_SPEED_X: number = this.SCREEN_HEIGTH * 0.008;
  private BALL_SPEED_Y: number = this.SCREEN_HEIGTH * 0.008;
  private BALL_RADIUS: number = this.SCREEN_WIDTH * 0.01;

  private readonly PLAYER_WIDTH_SCALE = 0.01;
  private readonly PLAYER_HEIGTH_SCALE = 0.25;
  private playerMarginX = 3;
  private playerPosY = 1920 / 2 - (1920 * this.PLAYER_HEIGTH_SCALE) / 2;

  private readonly GAME_MAX_SCORE = 10;

  private gamePlayers: Map<string, string>;



  constructor(
    private readonly cacheService: CacheService,
    private readonly userService: UserService,
    private readonly matchService: MatchService,
  ) {
    this.gamePlayers = new Map();
  }

  public server: Server;

  async startGame(owner: GameRoom, rival: GameRoom) {
    this.server.to(owner.rivalRoomId).emit('start', owner.user);
    this.server.to(rival.rivalRoomId).emit('start', rival.user);
  }

  async finishGame(gameRoomKey: string, playerId?: string) {
    const gameCache = await this.cacheService.getCache(gameRoomKey);
    //console.log(gameCache);
    if (gameCache) {
      const game = await this.getGameRoom(gameRoomKey);

      if (playerId) {
        if (game.player1 == playerId) game.player1_score = -1;
        else game.player2_score = -1;
      }
      else this.matchService.create({
        player1: game.player1_id,
        player2: game.player2_id,
        score1: game.player1_score,
        score2: game.player2_score
      });

      this.gamePlayers.delete(game.player1);
      this.gamePlayers.delete(game.player2);

      this.server
        .to(game.player1)
        .emit('client:finishGame', [game.player1_score, game.player2_score]);
      this.server
        .to(game.player2)
        .emit('client:finishGame', [game.player2_score, game.player1_score]);

      await this.cacheService.delCache(gameRoomKey);
    }
  }

  async match(socket: Socket, userId: number, invite?: string) {
    if(invite == undefined)
      await this.findWaitRoom(socket, userId);
    else
      await this.inviteJoinRoom(socket, invite, userId);
  }

  async findWaitRoom(socket: Socket, userId: number) {
    const rooms = await this.findRooms();
    for (let i = rooms.length - 1; i >= 0; i--) {
      const room: Room = await this.cacheService.getCache(rooms[i]);
      if(room.is_private)
        continue;
      if (room.player2 == null) {
        room.player2 = socket.id;
        room.player2_id = userId;
        const user1 = await this.getUser(room.player1_id);
        const user2 = await this.getUser(room.player2_id);
        const gameIndex = await this.createGameRoom(room.player1, {
          player1: room.player1,
          player2: room.player2,
          player1_id: room.player1_id,
          player2_id: userId,
          player1_score: 0,
          player2_score: 0,
          ball_pos: {
            X: this.SCREEN_WIDTH / 2,
            Y: this.SCREEN_HEIGTH / 2,
          },
          gameStatus: GameStatus.CountDown,
          gameStartTime: Date.now()
        });
        const game = await this.getGameRoom(gameIndex);
        await this.cacheService.delCache(rooms[i]);
        console.log('Game Created: ', gameIndex);
        await this.gamePlayers.set(room.player1, gameIndex);
        await this.gamePlayers.set(room.player2, gameIndex);
        socket.emit('client:startGame', user1);
        socket.to(room.player1).emit('client:startGame', user2);
        return;
      }
    }
    await this.createRoom(socket.id, {
      player1: socket.id,
      player1_id: userId,
      player2: null,
    });
  }

  async inviteJoinRoom(socket: Socket, key: string, userId : number, is_prvt = false) {
    const room : Room = await this.cacheService.getCache(ROOM_PREFIX + key);
    if (room && room.player2 == null) {
      room.player2 = socket.id;
      room.player2_id = userId;
      const user1 = await this.getUser(room.player1_id);
      const user2 = await this.getUser(room.player2_id);
      const gameIndex = await this.createGameRoom(room.player1, {
        player1: room.player1,
        player2: room.player2,
        player1_id: room.player1_id,
        player2_id: userId,
        ball_pos: {
          X: this.SCREEN_WIDTH / 2,
          Y: this.SCREEN_HEIGTH / 2,
        },
        gameStatus: GameStatus.CountDown,
        gameStartTime: Date.now(),
      });
      const game = await this.getGameRoom(gameIndex);
      await this.deleteRoom(ROOM_PREFIX + key);
      console.log('Game Created: ', gameIndex);
      await this.gamePlayers.set(room.player1, gameIndex);
      await this.gamePlayers.set(room.player2, gameIndex);
      socket.emit('client:startGame', user1);
      socket.to(room.player1).emit('client:startGame', user2);
      return
    }
    else
    await this.createRoom(key, {
      player1: socket.id,
      player1_id: userId,
      player2: null,
      is_private: true,
    });
  }

  async createGameRoom(key: string, gameRoom: Game) {
    key = GAME_PREFIX + key;

    gameRoom.player1_pos = {
      X: this.playerMarginX,
      Y: this.playerPosY,
    };
    gameRoom.player2_pos = {
      X: 1920 - this.playerMarginX,
      Y: this.playerPosY,
    };
    gameRoom.ball_pos = {
      X: 1920 / 2,
      Y: 1080 / 2,
    };
    gameRoom.player1_score = 0;
    gameRoom.player2_score = 0;
    gameRoom.ball_speed = await this.setBallRandomDirection(key);

    await this.cacheService.setCache(key, gameRoom);
    return key;
  }

  async getGameRoom(key: string): Promise<Game> {
    return this.cacheService.getCache(key);
  }

  async getGamePlayers() {
    return this.gamePlayers;
  }

  async getGameRooms() {
    const ret = await this.cacheService.getCaches();
    return ret.filter((room) => room.startsWith(GAME_PREFIX));
  }

  async moveBall(gameRoomKey: string) {
    const gameRoom: Game = await this.getGameRoom(gameRoomKey);

    gameRoom.ball_pos.X += gameRoom.ball_speed.X;
    gameRoom.ball_pos.Y += gameRoom.ball_speed.Y;

    const ballX = gameRoom.ball_pos.X + (gameRoom.ball_speed.X > 0 ? this.BALL_RADIUS : -this.BALL_RADIUS);
    const ballY = gameRoom.ball_pos.Y + (gameRoom.ball_speed.Y > 0 ? this.BALL_RADIUS : -this.BALL_RADIUS);

    if (ballY < 0 || ballY > this.SCREEN_HEIGTH)
      gameRoom.ball_speed.Y = -gameRoom.ball_speed.Y;
    else if (ballX <= 0 || ballX > this.SCREEN_WIDTH) {
      const target = ballX <= 0 ? 0 : 1;
      if (target == 0) {
        gameRoom.player2_score++;
        if (gameRoom.player2_score == this.GAME_MAX_SCORE) return this.finishGame(gameRoomKey);
        this.server.to(gameRoom.player2).emit('client:playSound', 1); // 1 = win sound
        this.server.to(gameRoom.player1).emit('client:playSound', 2); //2 = lose sound
      } else {
        gameRoom.player1_score++;
        if (gameRoom.player1_score == this.GAME_MAX_SCORE) return this.finishGame(gameRoomKey);
        this.server.to(gameRoom.player1).emit('client:playSound', 1);
        this.server.to(gameRoom.player2).emit('client:playSound', 2); //Todo: add lose sound
      }
      this.resetBall(gameRoomKey);
      this.server
        .to(gameRoom.player1)
        .emit('client:setScore', [
          gameRoom.player1_score,
          gameRoom.player2_score,
        ]);
      this.server
        .to(gameRoom.player2)
        .emit('client:setScore', [
          gameRoom.player2_score,
          gameRoom.player1_score,
        ]);
    }
  }

  async setBallRandomDirection(gameRoomKey: string): Promise<Vector2> {
    const gameRoom = await this.getGameRoom(gameRoomKey);
    return {
      X:
        Math.random() > 0.5
          ? this.SCREEN_WIDTH * 0.002
          : this.SCREEN_WIDTH * -0.002,
      Y: this.SCREEN_HEIGTH * 0.008,
    };
  }

  async resetBall(gameRoomKey: string) {
    const gameRoom: Game = await this.getGameRoom(gameRoomKey);

    gameRoom.ball_pos = {
      X: this.SCREEN_WIDTH / 2,
      Y: this.SCREEN_HEIGTH / 2,
    };
    gameRoom.ball_speed = await this.setBallRandomDirection(gameRoomKey);
  }

  async createRoom(key: string, room: Room) {
    console.log('Room Created: ', ROOM_PREFIX + key);
    await this.cacheService.setCache(ROOM_PREFIX + key, room);
  }

  async deleteRoom(key: string) {
    const rooms = await this.findRooms();
    const index = rooms.indexOf(key);
    if (index != -1) {
      await this.cacheService.delCache(key);
      console.log('Room Deleted Succesfully', key);
    }
  }

  async getRoom(key: string) : Promise<Room> {
    return await this.cacheService.getCache(key);
  }

  async findRoomByClientId(clientId: string) {
    const rooms = await this.findRooms();
    const roomKey = rooms.find(async (roomKey)  => {
      const room = await this.getRoom(roomKey);
      if(room.player1 == clientId || room.player2 == clientId)
        return roomKey;
    })
    return roomKey;
  }
  async findRooms(): Promise<string[]> {
    const ret = await this.cacheService.getCaches();
    return ret.filter((room) => room.startsWith(ROOM_PREFIX));
  }

  async getUser(id: number) {
    return await this.userService.getOne({ id: id });
  }

  async addOnlineUser(id: number) {
    const users: number[] = await this.cacheService.getCache('Online-Users');
    if (!users) await this.cacheService.setCache('Online-Users', [id]);
    else await this.cacheService.setCache('Online-Users', [...users, id]);
  }

  async delOnlineUser(id: number) {
    let users: number[] = await this.cacheService.getCache('Online-Users');
    const user = users.find((u) => u == id);
    if (user) {
      users = users.filter((number) => number !== id);
      await this.cacheService.setCache('Online-Users', users);
    }
  }

  async createKey() {
    const KEY_LEN = 10;
    let key;

    const KEYS = "ABCDEFGHIJKLMNOPRSTUVYZXWabcdefghijklmnoprstvyzxw123456789";
    for(let i = 0; i < KEY_LEN; i++)
      key += Math.floor(Math.random() % KEYS.length);
    return key;
  }
}

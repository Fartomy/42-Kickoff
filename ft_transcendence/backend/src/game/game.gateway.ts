import {
  ConnectedSocket,
  MessageBody,
  OnGatewayConnection,
  OnGatewayDisconnect,
  OnGatewayInit,
  SubscribeMessage,
  WebSocketGateway,
} from '@nestjs/websockets';
import {GameService} from './game.service';
import {Server, Socket} from 'socket.io';
import {GameStatus} from "./entities/game.entity";
import {UserService} from "../user/user.service";

@WebSocketGateway(9000, {
  namespace: 'game',
  cors: {
    origin: '*',
  },
})
export class GameGateway
  implements OnGatewayConnection, OnGatewayDisconnect, OnGatewayInit
{

  private readonly SCREEN_WIDTH = 1920;
  private readonly SCREEN_HEIGHT = 1080;
  private readonly PLAYER_WIDTH_SCALE = 0.01;
  private readonly PLAYER_HEIGHT_SCALE = 0.25;
  private readonly PLAYER_WIDTH = this.SCREEN_WIDTH * this.PLAYER_WIDTH_SCALE;
  private readonly PLAYER_HEIGHT = this.SCREEN_HEIGHT * this.PLAYER_HEIGHT_SCALE;
  private readonly PLAYER_MARGIN = this.PLAYER_WIDTH / 2;
  private readonly BALL_RADIUS = this.SCREEN_WIDTH * this.PLAYER_WIDTH_SCALE;

  constructor(private readonly gameService: GameService, private readonly userService: UserService) {
  }

  afterInit(server: Server) {
    this.gameService.server = server;
    setInterval(() => {
      this.updateGames();
    },25);
  }

  async handleConnection(client: Socket) {
    console.log('Connected Client: ', client.id);
  }

  async handleDisconnect(client: Socket) {
    console.log('Disconnected:  ', client.id);

    const gamePlayers = await this.gameService.getGamePlayers();
    console.log(gamePlayers);

    if(gamePlayers.get(client.id)) {
      const gameRoom = gamePlayers.get(client.id);
      const game = await this.gameService.getGameRoom(gameRoom);
      const playerId = game.player1 == client.id ? game.player1 : game.player2;

      await this.gameService.delOnlineUser(game.player1 == client.id ? game.player1_id : game.player2_id);
      await this.userService.update({id: game.player1_id}, {is_gamer: false})
      await this.userService.update({id: game.player2_id}, {is_gamer: false})
      await this.gameService.finishGame(gameRoom, playerId);

      console.log("Game Finish");
    }
    else {
      const room = await this.gameService.findRoomByClientId(client.id);
      await this.gameService.deleteRoom(room);
    }
  }

  async updateGames()
  {

    const rooms = await this.gameService?.getGameRooms();
    for(let i = 0; i < rooms.length; i++)
    {
      const room = await this.gameService.getGameRoom(rooms[i]);

      if(room.gameStatus == GameStatus.CountDown) {
        if(room.gameStartTime + 3000 < Date.now())
          room.gameStatus = GameStatus.Started;
      }
      else if(room.gameStatus == GameStatus.Started) {
        this.gameService.moveBall(rooms[i]);

        let ballMirrorX;
        if(room.ball_pos.X < 960)
          ballMirrorX = 960 + (960 - room.ball_pos.X);
        else
          ballMirrorX = 960 - (room.ball_pos.X - 960);

        this.gameService.server.to(room.player1).emit("client:updateGame", {rival: room.player2_pos, ballPos: room.ball_pos});
        this.gameService.server.to(room.player2).emit("client:updateGame", {rival : room.player1_pos, ballPos: {X: ballMirrorX, Y: room.ball_pos.Y}});
      }
    }

  }

  @SubscribeMessage('server:match')
  async match(
    @ConnectedSocket() socket: Socket,
    @MessageBody() body
  ) {
    //Normal Play Duzeltilecek Matchmaking
    const user = await this.gameService.getUser(body.id);
    await this.gameService.addOnlineUser(body.id);
    await this.userService.update({id: body.id}, {is_gamer: true})
    console.log('Emit Match ', socket.id, "User", user.full_name, body.id);
    return await this.gameService.match(socket, body.id, body.invite);
  }

  @SubscribeMessage('server:updatePlayer')
  async movePlayer(@ConnectedSocket() socket : Socket, @MessageBody() body : any)
  {
    const gamePlayers = await this.gameService.getGamePlayers();
    const gameId = gamePlayers.get(socket.id);
    const game = await this.gameService.getGameRoom(gameId);

    if(game.player1 == socket.id) {
      game.player1_pos = body;
    }
    else {
      game.player2_pos = body;
    }
  }

  @SubscribeMessage('server:hit')
  async hit(@ConnectedSocket() socket : Socket, @MessageBody() body : any)
  {
    const gamePlayers = await this.gameService.getGamePlayers();
    const gameId = gamePlayers.get(socket.id);
    const game = await this.gameService.getGameRoom(gameId);

    if(game.player1 == socket.id) {
      const playerPos = this.SCREEN_HEIGHT * game.player1_pos.Y / 100;
      if(game.ball_pos.X - this.BALL_RADIUS <= game.player1_pos.X + this.PLAYER_WIDTH && game.ball_pos.Y >= playerPos && game.ball_pos.Y <= (playerPos + this.PLAYER_HEIGHT)) {
        game.ball_speed.X = -game.ball_speed.X;
        game.ball_speed.X  = Math.min(Math.max(game.ball_speed.X * 1.1, -10), 10);
      }
    }
    else
    {
      const playerPos = this.SCREEN_HEIGHT * game.player2_pos.Y / 100;
      if(game.ball_pos.X + this.BALL_RADIUS >= playerPos && game.ball_pos.Y >= playerPos && playerPos + this.PLAYER_HEIGHT) {
        game.ball_speed.X = -game.ball_speed.X;
        game.ball_speed.X  = Math.min(Math.max(game.ball_speed.X * 1.1, -10), 10);
      }
    }
  }


}

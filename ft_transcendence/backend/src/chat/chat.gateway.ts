import {
  OnGatewayConnection,
  OnGatewayDisconnect,
  SubscribeMessage,
  WebSocketGateway,
  WebSocketServer,
} from '@nestjs/websockets';
import { ChannelService } from '../channel/channel.service';
import { ChannelUser } from '../friend/entities/channel-user.entity';
import * as bcrypt from 'bcrypt';
import { Channel } from '../channel/entities/channel.entity';
import { UserService } from '../user/user.service';

interface JoinChannelPayload {
  channelId: number;
  channelPassword: string;
}

@WebSocketGateway(9000, {
  namespace: 'chat',
  cors: {
    origin: '*',
  },
})
export class ChatGateway implements OnGatewayConnection, OnGatewayDisconnect {
  @WebSocketServer() server;

  private connectedClients = new Map<number, any>();

  constructor(
    private readonly channelService: ChannelService,
    private readonly userService: UserService,
  ) {}

  afterInit(): void {
    console.log('websocket initialized ');
  }

  handleConnection(client: any, ...args): void {
    //console.log('client connected', client.id);
  }

  handleDisconnect(client: any): any {
    console.log(client.id, 'disconnected');
    for (const [key, value] of this.connectedClients.entries()) {
      if (value === client.id) {
        this.userService.update({ id: key }, { is_online: false });
        console.log('Key:', key);
        break;
      }
    }

    this.connectedClients.delete(client.id);
  }

  // direct message
  @SubscribeMessage('connect-user')
  handleConnectUser(client: any, payload: any): any {
    this.connectedClients.set(payload, client.id);
    this.userService.update({ id: payload }, { is_online: true });
    console.log('client: ', this.connectedClients);
  }

  @SubscribeMessage('message')
  handleMessage(client: any, payload: any): any {
    const receiverId = payload.recieverId;
    console.log(payload);
    const receiver = this.connectedClients.get(receiverId);
    console.log(this.connectedClients);
    console.log('reciever: ', receiver);

    if (receiver) {
      this.server.to(receiver).emit('message', payload);
    }
  }

  // channel message
  @SubscribeMessage('join-channel')
  async handleJoinChannel(client: any, payload: JoinChannelPayload) {
    const { channelId, channelPassword } = payload;

    if (!channelPassword) {
      console.log('joined channel: ', client.id, payload);
      client.join(payload.toString());
    } else {
      const channel = await this.channelService.findOne({
        where: {
          id: channelId,
        },
      });

      bcrypt.compare(channelPassword, channel.password, (err, res) => {
        if (res) {
          console.log('joined channel: ', client.id, payload);
          client.join(channelId.toString());
        }
      });
    }
  }

  @SubscribeMessage('leave-channel')
  handleLeaveChannel(client: any, payload: any): any {
    const channelId = payload;
    console.log('left channel: ', client.id, payload);
    client.leave(channelId.toString());
  }

  @SubscribeMessage('channel-message')
  async handleChannelMessage(client: any, payload: any) {
    const channel = await this.channelService.findMember(
      payload.channelId,
      payload.userId,
    );

    if (channel.is_banned || channel.is_muted) {
      client.disconnect();
      return;
    }

    const channelId: string = payload.channelId.toString();

    this.server.to(channelId).emit('channel-message', payload);
  }
}

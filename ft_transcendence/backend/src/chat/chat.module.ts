import { ChatGateway } from './chat.gateway';
import { Module } from '@nestjs/common';
import { ChannelModule } from '../channel/channel.module';
import { TypeOrmModule } from '@nestjs/typeorm';
import { Channel } from '../channel/entities/channel.entity';
import { ChannelUser } from '../friend/entities/channel-user.entity';
import { ChannelService } from '../channel/channel.service';
import { User } from '../user/user.entity';
import { UserService } from '../user/user.service';
import { UserModule } from '../user/user.module';
import { IntraService } from '../intra/intra.service';
import { MatchService } from '../match/match.service';
import { Match } from '../match/entities/match.entity';

@Module({
  imports: [
    UserModule,
    ChannelModule,
    TypeOrmModule.forFeature([Channel, ChannelUser, User, Match]),
  ],
  providers: [
    ChatGateway,
    ChannelService,
    UserService,
    IntraService,
    MatchService,
  ],
})
export class ChatModule {}

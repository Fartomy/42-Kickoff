import { Module } from '@nestjs/common';
import { ChannelService } from './channel.service';
import { ChannelController } from './channel.controller';
import { TypeOrmModule } from '@nestjs/typeorm';
import { Channel } from './entities/channel.entity';
import { ChannelUser } from '../friend/entities/channel-user.entity';
import { User } from '../user/user.entity';
import { UserService } from '../user/user.service';
import { UserModule } from '../user/user.module';
import {MatchModule} from "../match/match.module";
import {IntraModule} from "../intra/intra.module";

@Module({
  imports: [UserModule, TypeOrmModule.forFeature([Channel, ChannelUser, User]), IntraModule, MatchModule],
  controllers: [ChannelController],
  providers: [ChannelService, UserService],
})
export class ChannelModule {}

import { Module } from '@nestjs/common';
import { FriendService } from './friend.service';
import { FriendController } from './friend.controller';
import { TypeOrmModule } from '@nestjs/typeorm';
import { Friend } from './entities/friend.entity';
import { UserModule } from '../user/user.module';
import { UserService } from '../user/user.service';
import { User } from '../user/user.entity';
import {MatchModule} from "../match/match.module";
import {IntraModule} from "../intra/intra.module";

@Module({
  imports: [TypeOrmModule.forFeature([Friend, User]), UserModule, IntraModule, MatchModule],
  controllers: [FriendController],
  providers: [FriendService, UserService],
  exports: [FriendService],
})
export class FriendModule {}

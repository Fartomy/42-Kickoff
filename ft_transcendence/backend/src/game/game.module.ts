import { Module } from '@nestjs/common';
import { GameService } from './game.service';
import { GameGateway } from './game.gateway';
import { UserModule } from 'src/user/user.module';
import { CacheModule } from 'src/cache/cache.module';
import { GameController } from './game.controller';
import {MatchModule} from "../match/match.module";
import {MatchService} from "../match/match.service";
import {UserService} from "../user/user.service";
import {TypeOrmModule} from "@nestjs/typeorm";
import {User} from "../user/user.entity";
import {Match} from "../match/entities/match.entity";
import {IntraService} from "../intra/intra.service";

@Module({
  controllers: [GameController],
  imports: [CacheModule, UserModule,MatchModule, TypeOrmModule.forFeature([User, Match])],
  providers: [GameGateway, GameService, UserService, IntraService],
  exports: [GameService],
})
export class GameModule {}

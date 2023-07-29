import { Module } from '@nestjs/common';
import { AuthModule } from './auth/auth.module';
import { TypeOrmModule } from '@nestjs/typeorm';
import { UserModule } from './user/user.module';
import { TokenModule } from './token/token.module';
import { ChatModule } from './chat/chat.module';
import { FriendModule } from './friend/friend.module';
import { ChannelModule } from './channel/channel.module';
import { GameModule } from './game/game.module';
import { CacheModule } from './cache/cache.module';
import config from './config';
import {MatchModule} from "./match/match.module";
import { join } from 'path';
import {ServeStaticModule} from "@nestjs/serve-static";

@Module({
  imports: [
    TypeOrmModule.forRoot({
      type: 'postgres',
      host: config.database.host,
      port: config.database.port,
      username: config.database.username,
      password: config.database.password,
      database: config.database.databaseName,
      entities: [__dirname + '/../**/*.entity.js'],
      synchronize: true,
    }),
    AuthModule,
    UserModule,
    TokenModule,
    ChatModule,
    FriendModule,
    ChannelModule,
    GameModule,
    CacheModule,
    MatchModule,
    ServeStaticModule.forRoot({
      rootPath: join(__dirname, '..', 'public'),
    }),
  ],
})
export class AppModule {}

import { Module } from '@nestjs/common';
import { AuthService } from './auth.service';
import { AuthController } from './auth.controller';
import { JwtStrategy } from './strategies/jwt.strategy';
import { TokenModule } from '../token/token.module';
import { UserModule } from '../user/user.module';
import { IntraModule } from 'src/intra/intra.module';
import { TypeOrmModule } from '@nestjs/typeorm';
import { GoogleAuthenticator } from './2FA/google-auth.entity';

@Module({
  controllers: [AuthController],
  imports: [
    UserModule,
    TokenModule,
    IntraModule,
    TypeOrmModule.forFeature([GoogleAuthenticator]),
  ],
  providers: [AuthService, JwtStrategy],
})
export class AuthModule {}

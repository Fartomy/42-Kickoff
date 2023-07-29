import * as speakeasy from 'speakeasy';
import * as qrcode from 'qrcode';
import { Injectable, UnauthorizedException } from '@nestjs/common';
import { UserService } from '../user/user.service';
import { UserDto } from '../user/dto/user.dto';
import { TokenService } from '../token/token.service';
import { IntraService } from 'src/intra/intra.service';
import { CallbackDto } from './dto/callback.dto';
import { InjectRepository } from '@nestjs/typeorm';
import { GoogleAuthenticator } from './2FA/google-auth.entity';
import { Repository } from 'typeorm';
import { IJwtPayload } from 'src/interfaces/jwt-payload.interface';

@Injectable()
export class AuthService {
  constructor(
    @InjectRepository(GoogleAuthenticator)
    private readonly googleAuth: Repository<GoogleAuthenticator>,
    private readonly userService: UserService,
    private readonly tokenService: TokenService,
    private readonly intraService: IntraService,
  ) {}

  async callback(body: CallbackDto) {
    const intraUser = await this.intraService.getMe(body.code);
    const userData: UserDto = this.intraService.parseUser(intraUser);
    const intra_id = userData.intra_id;

    const isUserExist = await this.userService.isExist({ intra_id });

    if (!isUserExist) await this.userService.create(userData);
    else await this.userService.update({
      intra_id: intraUser.id
    }, userData);

    let user: any = await this.userService.getOne({ intra_id });

    const token = this.tokenService.createJwt({ id: user.id });

    if(!isUserExist)
      user = {...user, is_first_login: true};

    if (user.twoFA) {
      return { user: { id: user.id } };
    }

    return { user, token };
  }

  async verify2FA(userId: number, code: string) {
    const secret = await this.googleAuth.findOne({
      where: { user: { id: userId } },
    });

    if (!secret) {
      throw new UnauthorizedException();
    }

    const isVerified = speakeasy.totp.verify({
      secret: secret.ascii,
      encoding: 'ascii',
      token: code,
    });

    if (!isVerified) {
      throw new UnauthorizedException();
    }

    const user = await this.userService.getOne({ id: userId });

    const accessToken = this.tokenService.createJwt({ id: userId });

    return { user, token: accessToken };
  }

  async myAccount(id: number) {
    return this.userService.getOne({ id });
  }

  async getTwoFactorQrCode(user: IJwtPayload) {
    const secret = await this.googleAuth.findOne({
      where: { user: { id: user.id } },
    });

    if (!secret) {
      const newSecret = speakeasy.generateSecret({
        name: 'Ebul Feth',
      });

      await this.googleAuth.save(
        this.googleAuth.create({
          ...newSecret,
          user: { id: user.id },
        }),
      );
      return qrcode.toDataURL(newSecret.otpauth_url);
    }

    return qrcode.toDataURL(secret.otpauth_url);
  }
}

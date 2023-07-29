import { Controller, Get, Post, Body, ParseIntPipe } from '@nestjs/common';
import { AuthService } from './auth.service';
import { CallbackDto } from './dto/callback.dto';
import { UseAuth } from 'src/@decorators/auth.decorator';
import { User } from 'src/@decorators/user.decorator';
import { IJwtPayload } from 'src/interfaces/jwt-payload.interface';

@Controller('auth')
export class AuthController {
  constructor(private readonly authService: AuthService) {}

  @Get('2fa')
  @UseAuth()
  async getTwoFactorQrCode(@User() user: IJwtPayload) {
    return await this.authService.getTwoFactorQrCode(user);
  }

  @Post('callback')
  async callback(@Body() body: CallbackDto) {
    return await this.authService.callback(body);
  }

  @Post('2fa/verify')
  async verify2FA(
    @Body('code') code: string,
    @Body('userId', ParseIntPipe) userId: number,
  ) {
    return await this.authService.verify2FA(userId, code);
  }

  @UseAuth()
  @Get('my-account')
  myAccount(@User() user: IJwtPayload) {
    return this.authService.myAccount(user.id);
  }
}

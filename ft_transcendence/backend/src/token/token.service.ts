import { Injectable } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { IJwtPayload } from 'src/interfaces/jwt-payload.interface';

@Injectable()
export class TokenService {
  constructor(private readonly jwtService: JwtService) {}

  createJwt(jwtData: IJwtPayload) {
    return this.jwtService.sign(jwtData);
  }

  verifyJwt(token: string) {
    return this.jwtService.verify<IJwtPayload>(token);
  }
}

import { Controller, Get } from '@nestjs/common';
import { GameService } from './game.service';
import { UseAuth } from 'src/@decorators/auth.decorator';
import { User } from 'src/@decorators/user.decorator';
import { IJwtPayload } from 'src/interfaces/jwt-payload.interface';

@UseAuth()
@Controller('game')
export class GameController {
  constructor(private readonly gameService: GameService) {}

  @Get("create-match")
  async create() {
      return await this.gameService.createKey();
  }

}

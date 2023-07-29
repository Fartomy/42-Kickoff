import { UseGuards } from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';

export function UseAuth() {
  return UseGuards(AuthGuard('jwt'));
}

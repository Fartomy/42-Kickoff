import { IsEnum, IsNumber } from 'class-validator';
import { FriendStatus } from '../entities/friend.entity';

export class CreateFriendDto {
  @IsNumber()
  user: number;

  @IsNumber()
  friend: number;

  @IsEnum(FriendStatus)
  status: FriendStatus;
}

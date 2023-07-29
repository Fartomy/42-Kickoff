import { PartialType } from '@nestjs/mapped-types';
import { CreateChannelDto } from './create-channel.dto';
import { ChannelType } from '../entities/channel.entity';

export class UpdateChannelDto extends PartialType(CreateChannelDto) {
  type: ChannelType;

  password: string;
}

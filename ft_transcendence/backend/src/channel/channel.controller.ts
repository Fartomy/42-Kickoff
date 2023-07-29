import {
  Controller,
  Get,
  Post,
  Body,
  Param,
  Delete,
  UseGuards,
  Put,
  Query,
} from '@nestjs/common';
import { ChannelService } from './channel.service';
import { CreateChannelDto } from './dto/create-channel.dto';
import { UpdateChannelDto } from './dto/update-channel.dto';
import { AuthGuard } from '@nestjs/passport';
import { User } from '../@decorators/user.decorator';
import { UserService } from '../user/user.service';

@UseGuards(AuthGuard('jwt'))
@Controller('channel')
export class ChannelController {
  constructor(
    private readonly channelService: ChannelService,
    private readonly userService: UserService,
  ) {}

  @Post()
  create(@User() currentUser: any, @Body() createChannelDto: CreateChannelDto) {
    return this.channelService.create(currentUser, createChannelDto);
  }

  @Post('/add-member/:id')
  async addMember(
    @User() currentUser: any,
    @Param('id') id: number,
    @Body() body: any,
  ) {
    return await this.channelService.addMember(currentUser, id, body);
  }

  @Post('/leave/:id')
  async leave(@User() currentUser: any, @Param('id') id: number) {
    return await this.channelService.leave(currentUser, id);
  }

  @Get()
  async findAll(@User() currentUser: any) {
    return await this.channelService.findAll({
      where: {
        is_banned: false,
        user: {
          id: currentUser.id,
        },
      },
      relations: ['channel'],
    });
  }

  @Get('/public')
  async findPublicChannels(@User() currentUser: any) {
    return await this.channelService.findPublicChannels(currentUser);
  }

  @Get('/non-members/:id')
  async findNonMembers(@User() currentUser: any, @Param('id') id: number) {
    return await this.userService.findNonChannelMembers(currentUser, id);
  }

  @Get('/members/:id')
  async findMembers(@Param('id') id: number) {
    return await this.channelService.findMembers(id);
  }

  @Get('/member/:id')
  async findMember(@Param('id') id: number, @Query('userId') userId: number) {
    return await this.channelService.findMember(id, userId);
  }

  @Put('/assign-admin/:id')
  async assignAdmin(
    @User() currentUser,
    @Param('id') id: number,
    @Body() body: any,
  ) {
    return await this.channelService.assignAdmin(currentUser, id, body.userId);
  }

  @Put('/member/:id')
  async updateMember(
    @Param('id') id: number,
    @Query('userId') userId: number,
    @Body() body: any,
  ) {
    return await this.channelService.updateMember(id, userId, body);
  }

  @Post('join/:id')
  async join(@User() currentUser: any, @Param('id') id: number) {
    return await this.channelService.joinChannel(currentUser.id, id);
  }

  @Get(':id')
  findOne(@Param('id') id: number) {
    return this.channelService.findOne({
      where: { id },
    });
  }

  @Post('check-password')
  async checkPassword(@Body() body: { id: number; password: string }) {
    return await this.channelService.checkPassword(body.id, body.password);
  }

  @Put(':id')
  update(@Param('id') id: string, @Body() updateChannelDto: any) {
    console.log(updateChannelDto);
    return this.channelService.update(+id, updateChannelDto);
  }

  @Delete(':id')
  remove(@Param('id') id: number) {
    return this.channelService.remove(+id);
  }
}

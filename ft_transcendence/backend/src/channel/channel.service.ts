import { ForbiddenException, Injectable } from '@nestjs/common';
import { CreateChannelDto } from './dto/create-channel.dto';
import { UpdateChannelDto } from './dto/update-channel.dto';
import { InjectRepository } from '@nestjs/typeorm';
import { Channel, ChannelType } from './entities/channel.entity';
import { In, Not, Repository } from 'typeorm';
import { ChannelUser } from '../friend/entities/channel-user.entity';
import * as bcrypt from 'bcrypt';

@Injectable()
export class ChannelService {
  constructor(
    @InjectRepository(Channel)
    private readonly channelRepository: Repository<Channel>,
    @InjectRepository(ChannelUser)
    private readonly channelUserRepository: Repository<ChannelUser>,
  ) {}

  async create(currentUser: any, createChannelDto: CreateChannelDto) {
    const channel = await this.channelRepository.insert(createChannelDto);
    await this.channelUserRepository.insert({
      channel: channel.identifiers[0].id,
      user: currentUser.id,
      is_owner: true,
      is_admin: true,
    });

    return channel;
  }

  async addMember(currentUser: any, id: number, body: any) {
    const channelId = parseInt(id.toString());
    const user = await this.channelUserRepository.findOne({
      where: {
        channel: {
          id: channelId,
        },
        user: {
          id: currentUser.id,
        },
      },
      relations: ['user', 'channel'],
    });

    if (!user) {
      throw new ForbiddenException("You don't have permission to add members.");
    }

    await this.channelUserRepository.insert({
      channel: {
        id: channelId,
      },
      user: body.userId,
    });
  }

  async joinChannel(userId: number, channelId: number) {
    await this.channelUserRepository.insert({
      channel: {
        id: channelId,
        type: ChannelType.PUBLIC,
      },
      user: {
        id: userId,
      },
    });
  }

  async leave(currentUser: any, id: number) {
    const channelId = parseInt(id.toString());
    const user = await this.channelUserRepository.findOne({
      where: {
        channel: {
          id: channelId,
        },
        user: {
          id: currentUser.id,
        },
      },
      relations: ['user', 'channel'],
    });

    if (!user) {
      throw new ForbiddenException("You don't have permission to leave.");
    }

    await this.channelUserRepository.delete({
      channel: {
        id: channelId,
      },
      user: {
        id: currentUser.id,
      },
    });
  }

  async assignAdmin(currentUser: any, channelId: number, userId: number) {
    const user = await this.channelUserRepository.findOne({
      where: {
        channel: {
          id: channelId,
        },
        user: {
          id: currentUser.id,
        },
      },
      relations: ['user', 'channel'],
    });

    if (!user || !user.is_owner) {
      throw new ForbiddenException(
        "You don't have permission to assign admin.",
      );
    }

    await this.channelUserRepository.update(
      {
        channel: {
          id: channelId,
        },
        user: {
          id: userId,
        },
      },
      {
        is_admin: true,
      },
    );
  }

  async findAll(query: any) {
    return await this.channelUserRepository.find(query);
  }

  async findMembers(id: number) {
    const channelId = parseInt(id.toString());
    return await this.channelUserRepository.find({
      where: {
        is_banned: false,
        channel: {
          id: channelId,
        },
      },
      relations: ['user'],
    });
  }

  async findMember(id: number, userId: number) {
    const channelId = parseInt(id.toString());
    const channelUserId = parseInt(userId.toString());
    return await this.channelUserRepository.findOne({
      where: {
        channel: {
          id: channelId,
        },
        user: {
          id: channelUserId,
        },
      },
      relations: ['user'],
    });
  }

  async findPublicChannels(currentUser: any) {
    const joinedChannels = await this.findAll({
      where: {
        user: {
          id: currentUser.id,
        },
      },
      relations: ['channel'],
    });

    const joinedChannelIds = joinedChannels.map(
      (channel) => channel.channel.id,
    );

    return await this.channelRepository.find({
      where: { id: Not(In(joinedChannelIds)), type: ChannelType.PUBLIC },
    });
  }

  async updateMember(id: number, userId: number, body: any) {
    const channelId = parseInt(id.toString());
    const channelUserId = parseInt(userId.toString());
    return await this.channelUserRepository.update(
      {
        channel: {
          id: channelId,
        },
        user: {
          id: channelUserId,
        },
      },
      body,
    );
  }

  async findOne(query: any): Promise<Channel> {
    return await this.channelRepository.findOne(query);
  }

  async checkPassword(id: number, password: string): Promise<boolean> {
    const channel = await this.channelRepository.findOne({ where: { id } });
    return await bcrypt.compare(password, channel.password);
  }

  async update(id: number, updateChannelDto: UpdateChannelDto) {
    if (updateChannelDto.type === ChannelType.PROTECTED) {
      updateChannelDto.password = await bcrypt.hash(
        updateChannelDto.password,
        10,
      );
    }
    return await this.channelRepository.update({ id }, updateChannelDto);
  }

  async remove(id: number) {
    await this.channelUserRepository.delete({ channel: { id } });
    return await this.channelRepository.delete({ id });
  }
}

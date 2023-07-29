import { Injectable } from '@nestjs/common';
import { CreateFriendDto } from './dto/create-friend.dto';
import { UpdateFriendDto } from './dto/update-friend.dto';
import { InjectRepository } from '@nestjs/typeorm';
import { Friend } from './entities/friend.entity';
import { Repository } from 'typeorm';

@Injectable()
export class FriendService {
  constructor(
    @InjectRepository(Friend)
    private readonly friendRepository: Repository<Friend>,
  ) {}

  async create(createFriendDto: CreateFriendDto) {
    return await this.friendRepository.insert(createFriendDto);
  }

  async findAll(query: any) {
    return await this.friendRepository.find(query);
  }

  async findOne(query: any) {
    return await this.friendRepository.findOne(query);
  }

  async update(id: number, updateFriendDto: UpdateFriendDto) {
    return await this.friendRepository.update({ id }, updateFriendDto);
  }

  async remove(id: number) {
    return await this.friendRepository.delete({ id });
  }
}

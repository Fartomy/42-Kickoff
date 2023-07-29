import config from 'src/config';
import { Injectable } from '@nestjs/common';
import { UserDto } from './dto/user.dto';
import { InjectRepository } from '@nestjs/typeorm';
import {
  DeleteResult,
  FindOptionsWhere,
  InsertResult,
  Repository,
  UpdateResult,
} from 'typeorm';
import { User } from './user.entity';
import { ChannelUser } from '../friend/entities/channel-user.entity';
import { Friend } from '../friend/entities/friend.entity';
import { MatchService } from '../match/match.service';
import { IntraService } from '../intra/intra.service';
import { UpdateProfileDto } from './dto/update-profile.dto';

@Injectable()
export class UserService {
  constructor(
    @InjectRepository(User) private readonly userRepository: Repository<User>,
    private readonly intraService: IntraService,
    private readonly matchService: MatchService,
  ) {}

  async isExist(where: FindOptionsWhere<User>) {
    return this.userRepository.exist({ where });
  }

  async getOne(where: FindOptionsWhere<User>): Promise<User> {
    return this.userRepository.findOneBy(where);
  }

  async getAll(): Promise<User[]> {
    return this.userRepository.find();
  }

  async findNonFriends(id: number) {
    return this.userRepository
      .createQueryBuilder('user')
      .leftJoin('user.friends', 'friend')
      .where('user.id != :userId', { userId: id })
      .andWhere((qb) => {
        const subQuery = qb
          .subQuery()
          .select('friend.friend')
          .from(Friend, 'friend')
          .where('friend.user = :userId', { userId: id })
          .getQuery();

        return 'user.id NOT IN ' + subQuery;
      })
      .getMany();
  }

  async findNonChannelMembers(currentUser: any, id: number) {
    return await this.userRepository
      .createQueryBuilder('user')
      .where('user.id != :userId', { userId: currentUser.id })
      .andWhere((qb) => {
        const subQuery = qb
          .subQuery()
          .select('channelUser.user')
          .from(ChannelUser, 'channelUser')
          .where('channelUser.channel = :channelId', { channelId: id })
          .getQuery();

        return 'user.id NOT IN ' + subQuery;
      })
      .getMany();
  }

  async getMatchHistory(id: number, limit: number) {
    return this.matchService.getMatchHistory(id, limit);
  }

  async getTotalWins() {
    return this.matchService.getTotalWins();
  }

  async create(user: UserDto): Promise<InsertResult> {
    return this.userRepository.insert(user);
  }

  async update(where: any, data: UserDto): Promise<UpdateResult> {
    return this.userRepository.update(where, data);
  }

  async delete(where: any): Promise<DeleteResult> {
    return this.userRepository.delete(where);
  }

  async getUser(user: string, token: string) {
    return this.intraService.getUser(user, token);
  }

  async updateProfile(
    user_id: number,
    data: UpdateProfileDto,
    file?: Express.Multer.File,
  ) {
    return this.userRepository.save(
      this.userRepository.create({
        id: user_id,
        ...data,
        avatar: file
          ? `http://localhost:${config.app.port}/uploads/${file.filename}`
          : undefined,
      }),
    );
  }
}

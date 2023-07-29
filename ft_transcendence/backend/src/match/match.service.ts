import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { Match } from './entities/match.entity';
import { MatchDto } from './dto/match.dto';

@Injectable()
export class MatchService {
  constructor(
    @InjectRepository(Match)
    private readonly matchRepository: Repository<Match>,
  ) {}

  async create(matchDto: MatchDto) {
    await this.matchRepository.save(matchDto);
  }

  async getMatchHistory(id: number, limit: number) {
    return this.matchRepository
      .createQueryBuilder('match')
      .leftJoin('match.player1', 'player1')
      .addSelect(['player1.full_name', 'player1.avatar'])
      .leftJoin('match.player2', 'player2')
      .addSelect(['player2.full_name', 'player2.avatar'])
      .where('match.player1Id = :id OR match.player2Id = :id', { id })
      .orderBy('match.id', 'DESC')
      .take(limit ?? 5)
      .getMany();
  }

  async getTotalWins() {
    const matchs = await this.matchRepository
      .createQueryBuilder('match')
      .leftJoinAndSelect('match.player1', 'player1')
      .leftJoinAndSelect('match.player2', 'player2')
      .getMany();

    const scores = new Map<
      number,
      { full_name?: string; avatar?: string; score: number }
    >();

    matchs.forEach((m: any) => {
      const players: number[] = [m.player1.id, m.player2.id];

      if (!scores.get(players[0]))
        scores.set(players[0], {
          full_name: m.player1.full_name,
          avatar: m.player1.avatar,
          score: 0,
        });
      if (!scores.get(players[1]))
        scores.set(players[1], {
          full_name: m.player2.full_name,
          avatar: m.player2.avatar,
          score: 0,
        });

      if (m.score1 > m.score2)
        scores.set(players[0], {
          ...scores.get(players[0]),
          score: scores.get(players[0]).score + 1,
        });
      else if (m.score2 > m.score1)
        scores.set(players[1], {
          ...scores.get(players[1]),
          score: scores.get(players[1]).score + 1,
        });
    });

    const res = Array.from(scores.values()).sort((a, b) => b.score - a.score);
    return res;
  }
}

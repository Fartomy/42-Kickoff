import { User } from 'src/user/user.entity';

export interface IScoreBoard {
  [x: string]: {
    user: User;
    score: number;
  };
}

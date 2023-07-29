import { User } from 'src/user/user.entity';
import {
  BaseEntity,
  Column,
  Entity,
  JoinColumn,
  OneToOne,
  PrimaryGeneratedColumn,
} from 'typeorm';

@Entity()
export class GoogleAuthenticator extends BaseEntity {
  @PrimaryGeneratedColumn()
  id: number;

  @Column()
  ascii: string;

  @Column()
  otpauth_url: string;

  @Column()
  hex: string;

  @Column()
  base32: string;

  @OneToOne(() => User, (user) => user.id)
  @JoinColumn()
  user: User;
}

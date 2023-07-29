import {Column, Entity, ManyToOne, OneToMany, PrimaryGeneratedColumn} from "typeorm";
import {User} from "../../user/user.entity";

@Entity()
export class Match {

    @PrimaryGeneratedColumn()
    id: number;

    @ManyToOne(() => User, (user) => user.id)
    player1: number;

    @Column()
    score1: number;

    @ManyToOne(() => User, (user) => user.id)
    player2: number;

    @Column()
    score2: number;

}
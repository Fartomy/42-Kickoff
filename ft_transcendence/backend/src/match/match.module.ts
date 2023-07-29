import {MatchService} from "./match.service";
import {Module} from "@nestjs/common";
import {TypeOrmModule} from "@nestjs/typeorm";
import {Match} from "./entities/match.entity";

@Module({
    imports: [TypeOrmModule.forFeature([Match])],
    exports: [MatchService],
    providers: [MatchService],
})
export class MatchModule {}
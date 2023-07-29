import { BadRequestException, Module } from '@nestjs/common';
import { UserService } from './user.service';
import { UserController } from './user.controller';
import { TokenModule } from '../token/token.module';
import { TypeOrmModule } from '@nestjs/typeorm';
import { User } from './user.entity';
import { MatchModule } from '../match/match.module';
import { IntraModule } from '../intra/intra.module';
import { MulterModule } from '@nestjs/platform-express';
import { diskStorage } from 'multer';

@Module({
  controllers: [UserController],
  imports: [
    TypeOrmModule.forFeature([User]),
    TokenModule,
    MatchModule,
    IntraModule,
    MulterModule.register({
      storage: diskStorage({
        destination: './public/uploads',
        filename: (req, file, cb) => {
          file.filename = Date.now() + '-' + file.originalname;
          if (!file.mimetype.includes('image/'))
            return cb(new BadRequestException('File is not image'), null);
          cb(null, file.filename);
        },
      }),
    }),
  ],
  providers: [UserService],
  exports: [UserService],
})
export class UserModule {}

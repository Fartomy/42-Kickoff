import { Module } from '@nestjs/common';
import { IntraService } from './intra.service';

@Module({
  providers: [IntraService],
  exports: [IntraService],
})
export class IntraModule {}

import { Module } from '@nestjs/common';
import { CacheService } from './cache.service';
import { CacheModule as NestCacheModule } from '@nestjs/cache-manager';

@Module({
  imports: [NestCacheModule.register()],
  providers: [CacheService],
  exports: [CacheService],
})
export class CacheModule {}

import { IsBooleanString, IsOptional, IsString } from 'class-validator';

export class UpdateProfileDto {
  @IsOptional()
  @IsString()
  login: string;

  @IsOptional()
  @IsBooleanString()
  twoFA: boolean;
}

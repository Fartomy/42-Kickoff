import config from 'src/config';
import axios from 'axios';
import { Injectable, NotFoundException } from '@nestjs/common';
import { UserDto } from '../user/dto/user.dto';
import { IIntraToken } from './intra-token.interface';

@Injectable()
export class IntraService {
  private readonly intraApiService = axios.create({
    baseURL: config.intra.apiUrl,
  });

  private async createIntraToken(code: string) {
    const res = await axios.post(
      config.intra.tokenUrl,
      {
        grant_type: 'authorization_code',
        client_id: config.intra.clientId,
        client_secret: config.intra.clientSecret,
        redirect_uri: config.intra.redirectUrl,
        code,
      },
      {
        headers: {
          'Content-Type': 'application/json',
          'Accept-Encoding': 'identity',
        },
      },
    );
    const token: IIntraToken = res.data;
    this.intraApiService.defaults.headers.common.Authorization = `Bearer ${token.access_token}`;
    return token.access_token;
  }

  async getMe(code: string): Promise<any> {
    const intraToken = await this.createIntraToken(code);

    const res = await this.intraApiService.get('/me');
    return { ...res.data, token: intraToken };
  }

  async getUser(user: string, token: string) {
    this.intraApiService.defaults.headers.common.Authorization = `Bearer ${token}`;
    try {
      const res = await this.intraApiService.get('/users/' + user);
      return res.data;
    } catch {
      return null;
    }
  }

  parseUser(user: any): UserDto {
    return {
      intra_id: user.id,
      login: user.login,
      full_name: user.displayname,
      email: user.email,
      avatar: user.image.link,
    };
  }
}

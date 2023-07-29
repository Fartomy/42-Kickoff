interface IUser {
  id: number;
  name: string;
  intra_id: number;
  full_name: string;
  email: string | null;
  avatar: string | null;
  twoFA: boolean;
  login: string;
}

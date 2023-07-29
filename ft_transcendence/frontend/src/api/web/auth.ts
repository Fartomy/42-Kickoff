import axios from "@/lib/axios";

export async function loginAPI(
  code: string
): Promise<{ user: IUser; token?: string }> {
  return axios.post("/auth/callback", { code }).then((resp) => resp.data);
}

export async function myAccountAPI(): Promise<IUser> {
  return axios.get("/auth/my-account").then((resp) => resp.data);
}

export async function get2FAQrCodeAPI(): Promise<string> {
  return axios.get("/auth/2fa").then((resp) => resp.data);
}

export async function verify2FAAPI(data: { code: string; userId: number }) {
  return axios.post("/auth/2fa/verify", data).then((resp) => resp.data);
}

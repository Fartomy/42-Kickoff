import axios from "@/lib/axios";

const USER_ENDPOINT = "/user";

export async function updateProfileAPI(data: FormData): Promise<void> {
  return axios
    .put(`${USER_ENDPOINT}/update-profile`, data)
    .then((resp) => resp.data);
}

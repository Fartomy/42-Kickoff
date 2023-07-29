import Axios, { AxiosError, InternalAxiosRequestConfig } from "axios";

const axios = Axios.create({
  baseURL: process.env.NEXT_PUBLIC_BACKEND_URL,
});

axios.interceptors.response.use(
  (response) => response,
  (error: AxiosError) =>
    Promise.reject(error.response?.data || "Bir şeyler ters gitti")
);

export default axios;

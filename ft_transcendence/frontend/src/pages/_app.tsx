import "@/styles/globals.css";
import AuthProvider from "@/auth/AuthContext";
import { Toaster } from "react-hot-toast";
import { ReactNode } from "react";

interface IAppProps {
  Component: Function & { getLayout?: (page: ReactNode) => ReactNode };
  pageProps: any;
}

export default function App({ Component, pageProps }: IAppProps) {
  const getLayout = Component.getLayout || ((page) => page);

  return (
    <>
      <AuthProvider>
        <Toaster />
        {getLayout(<Component {...pageProps} />)}
      </AuthProvider>
    </>
  );
}

import {
  get2FAQrCodeAPI,
  loginAPI,
  myAccountAPI,
  verify2FAAPI,
} from "@/api/web/auth";
import { setSession } from "@/utils/jwt";
import {
  ReactNode,
  createContext,
  useCallback,
  useContext,
  useEffect,
  useState,
} from "react";

interface IAuthContext {
  get2FAQrCode: () => Promise<string>;
  login: (code: string) => Promise<any>;
  logout: () => void;
  user: IUser | null;
  verify2FA: (code: string, userId: number) => Promise<void>;

  isInitializing: boolean;
  isAuthenticated: boolean;
}

const AuthContext = createContext<IAuthContext>({
  get2FAQrCode: async () => "",
  async verify2FA(code: string, userId: number) {},
  async login(code: string) {},
  logout() {},
  user: null,
  isInitializing: true,
  isAuthenticated: false,
});

export const useAuthContext = () => useContext(AuthContext);

export default function AuthProvider({ children }: { children: ReactNode }) {
  const [user, setUser] = useState<IUser | null>(null);
  const [isInitializing, setIsInitializing] = useState(true);
  const [isAuthenticated, setIsAuthenticated] = useState(false);

  const get2FAQrCode = async () => {
    try {
      const qr = await get2FAQrCodeAPI();
      return qr;
    } catch (error) {
      console.log(error);
    }
    return "";
  };

  const login = async (code: string) => {
    try {
      const data = await loginAPI(code);

      if (data.token) {
        setSession(data.token);
      }
      authenticated(data.user);
      return data;
    } catch (error) {
      reset();
      setSession(null);
      return Promise.reject(error);
    }
  };

  const verify2FA = async (code: string, userId: number) => {
    try {
      const data = await verify2FAAPI({ code, userId });
      console.log(data);
      setSession(data.token);
      authenticated(data.user);
    } catch (error) {}
  };

  const logout = () => {
    console.log("reset");
    reset();
  };

  const authenticated = (user: IUser) => {
    setUser(user);
    setIsInitializing(false);
    setIsAuthenticated(true);
  };

  const reset = () => {
    setSession(null);
    setUser(null);
    setIsInitializing(false);
    setIsAuthenticated(false);
  };

  const initialize = useCallback(async (token: string) => {
    try {
      setSession(token);
      const user = await myAccountAPI();
      authenticated(user);
    } catch (error) {
      reset();
    }
  }, []);

  useEffect(() => {
    if (typeof window !== "undefined") {
      const token = localStorage.getItem("token");

      if (!token) {
        reset();
      } else {
        initialize(token);
      }
    }
  }, [initialize]);

  return (
    <AuthContext.Provider
      value={{
        login,
        logout,
        get2FAQrCode,
        verify2FA,
        user,
        isAuthenticated,
        isInitializing,
      }}
    >
      {children}
    </AuthContext.Provider>
  );
}

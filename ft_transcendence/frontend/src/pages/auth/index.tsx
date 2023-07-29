import { useAuthContext } from "@/auth/AuthContext";
import { useEffect } from "react";

export default function Login() {
  const { logout } = useAuthContext();

  useEffect(() => {
    if (typeof window !== "undefined") {
      logout();
    }
  }, []);

  return (
    <div className="hero min-h-screen bg-base-200">
      <div className="card flex-shrink-0 w-full max-w-sm shadow-2xl bg-base-100">
        <div className="card-body">
          <div className="form-control">
            <a
              href={process.env.NEXT_PUBLIC_INTRA_API_URL}
              className="btn btn-primary"
            >
              Login with Intra !
            </a>
          </div>
        </div>
      </div>
    </div>
  );
}

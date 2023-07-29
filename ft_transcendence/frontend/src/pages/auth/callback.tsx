import toast from "react-hot-toast";
import { useEffect, useState } from "react";
import { useRouter } from "next/router";
import { useAuthContext } from "@/auth/AuthContext";

export default function Callback() {
  const { query } = useRouter();

  const { login, verify2FA, user } = useAuthContext();

  const [enabled2FA, setEnabled2FA] = useState(false);

  const [twoFactorAuthCode, setTwoFactorAuthCode] = useState("");

  const handleClickConfirm = async () => {
    if (twoFactorAuthCode.length !== 6) {
      toast.error("Google auth code length must be 6 !");
    } else {
      try {
        if (typeof query.code === "string") {
          const data = await verify2FA(twoFactorAuthCode, user?.id!);
          window.location.href = "/";
        }
      } catch (error) {
        const err = error as any;

        if (err?.statusCode === 401) {
          toast.error(err.message);
        } else {
          toast.error("Session is expired. Redirecting...");
          setTimeout(() => {
            window.location.href = "/";
          }, 2000);
          console.error(err);
        }
      }
    }
  };

  useEffect(() => {
    if (!query.code) return;

    login(query.code as string).then((data : any) => {
      if (data.token) {
        if(data.user.is_first_login)
          window.location.href = "/profile";
        else
          window.location.href = "/";
      } else {
        setEnabled2FA(true);
      }
    });
  }, [query.code]);

  return (
    <div className="hero min-h-screen">
      {enabled2FA ? (
        <div className="flex flex-col items-center gap-12">
          <div className="flex gap-2">
            <input
              type="number"
              onChange={(e) => setTwoFactorAuthCode(e.target.value)}
              placeholder="Google Authenticator Code"
              className="input input-bordered input-success w-full "
            />
            <button
              onClick={handleClickConfirm}
              className="btn btn-accent disabled"
            >
              Confirm
            </button>
          </div>
        </div>
      ) : (
        <h3>Redirecting ...</h3>
      )}
    </div>
  );
}

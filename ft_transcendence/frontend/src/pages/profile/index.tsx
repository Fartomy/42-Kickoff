import toast from "react-hot-toast";
import { ReactNode, useEffect, useState } from "react";
import DashboardLayout from "@/layouts/DashboardLayout";
import { useAuthContext } from "@/auth/AuthContext";
import { updateProfileAPI } from "@/api/web/profile";

Profile.getLayout = (page: ReactNode) => (
  <DashboardLayout>{page}</DashboardLayout>
);

export default function Profile() {
  const { get2FAQrCode, user } = useAuthContext();

  const [login, setLogin] = useState(user?.login || "");
  const [file, setFile] = useState<File>();
  const [qrCode, setQrCode] = useState<string>();
  const [enable2Fa, setEnable2FA] = useState(user?.twoFA);

  const onFileChange = (e: any) => {
    setFile(e.target.files[0]);
  };

  const onSubmit = (e: any) => {
    e.preventDefault();

    const bodyFormData = new FormData();
    bodyFormData.append("login", login);
    bodyFormData.append("avatar", file ?? "");
    bodyFormData.append("twoFA", String(enable2Fa));

    updateProfileAPI(bodyFormData)
      .then(() => toast.success("Success"))
      .catch((e) => toast.error(e.message));
  };

  useEffect(() => {
    get2FAQrCode().then((data) => setQrCode(data));
  }, []);

  return (
    <>
      <div>
        <div className="flex gap-10 p-10">
          <div className="avatar online">
            <div className="w-24 rounded-full">
              <img src={user?.avatar || ""} />
            </div>
          </div>

          <div className="flex-1">
            <h1 className="text-4xl font-bold">{user?.full_name}</h1>
          </div>
        </div>

        <div className="flex flex-col items-center gap-12">
          <div className="inline-flex item-center flex-col">
            <h3 className=" mb-2 ">Google Authenticator Qr Code</h3>
            <img src={qrCode} />
            <div className="form-control">
              <label className="label cursor-pointer">
                <span className="label-text ">Enable</span>
                <input
                  type="checkbox"
                  className="toggle"
                  checked={enable2Fa}
                  onChange={(e) => setEnable2FA(e.target.checked)}
                />
              </label>
            </div>
          </div>
        </div>

        <div className="card">
          <div className="card-body">
            <h2 className="card-title">Profile</h2>
            <form onSubmit={onSubmit}>
              <div className="form-control">
                <label className="label">
                  <span className="label-text">Username</span>
                </label>
                <input
                  type="text"
                  name="login"
                  value={login}
                  onChange={(e) => setLogin(e.target.value)}
                  className="input input-bordered"
                />
                <label className="label">
                  <span className="label-text">Avatar</span>
                </label>
                <input
                  type="file"
                  name="file"
                  onChange={onFileChange}
                  className="file-input file-input-bordered w-full"
                />
              </div>

              <button className="btn btn-outline btn-success mt-6">Save</button>
            </form>
          </div>
        </div>
      </div>
    </>
  );
}

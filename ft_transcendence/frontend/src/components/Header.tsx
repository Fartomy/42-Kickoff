import Link from "next/link";
import { useAuthContext } from "@/auth/AuthContext";

interface Profile {
  full_name: string;
  email: string;
  avatar: string;
}

export default function Header() {

  const { user, logout } = useAuthContext();

  return (
    <>
      <div className="navbar bg-base-300 flex justify-around">
        <div>
          <h4 className="text-white text-4xl font-bold italic animate-bounce">
           🛡️ Ebu'l ⚓️ Feth 🗡️
          </h4>
        </div>

        <div className="align-middle flex items-center">
          <ul className="menu menu-horizontal flex items-center">
            <div className="text-center">
              <Link href={"/"} className="btn btn-ghost items-center justify-center">
                Home
              </Link>
            </div>
            <div>
              <Link href={"/chat"} className="btn btn-ghost ">
                Chat
              </Link>
            </div>
            <div>
              <Link href={"/game/game"} className="btn btn-ghost">
                Play
              </Link>
            </div>
          </ul>

          <div className="dropdown dropdown-end z-40 ">
            <label
              tabIndex={0}
              className="btn btn-ghost btn-circle avatar placeholder"
            >
              {user?.avatar ? (
                <div className="w-10 rounded-full">
                  <img src={user?.avatar || ""} />
                </div>
              ) : (
                <div className="bg-neutral-focus text-neutral-content rounded-full w-24">
                  <span className="text-3xl">{user?.full_name[0]}</span>
                </div>
              )}
            </label>

            <ul className=" p-2 dropdown-content menu bg-base-100 rounded-box w-52">
              <li>
                <Link href="/profile" className="justify-between">
                  Profile
                </Link>
              </li>
              <li>
                <a href="#" className="justify-between" onClick={logout}>
                  Logout
                </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </>
  );
}

import {useRouter} from "next/router";
import {useEffect, useState} from "react";
import axios from "@/lib/axios";
import MatchHistory, {matchInfo} from "@/components/MatchHistory";
import DashboardLayout from "@/layouts/DashboardLayout";
import {IoGameController} from "react-icons/io5";
import {BsTrophyFill} from "react-icons/bs";
import {FaAward} from "react-icons/fa";


Profile.getLayout = (page: any) => <DashboardLayout>{page}</DashboardLayout>

export default function Profile()
{
    const router = useRouter();
    const [user, setUser] : any  = useState(null);
    const [matchs, setMatchs] : any  = useState();

    useEffect(() => {
       const userId = router.query.id;

       if(!userId)
           return;

       axios.get("/user/user/" + userId).then((res) => {
           setUser(res.data);
           const matchs = matchInfo(res.data.full_name, res.data.matchs);
           setMatchs(matchs);
       }).catch((e) => {
           router.push("/");
       });
    },[router]);


    return (
        <div className="container h-screen w-full flex flex-wrap justify-center items-center">

            <div>
                <div className="stats shadow">
                    <div className="stat">
                        <div className="stat-figure">
                            <div className="avatar online">
                                <div className="w-16 rounded-full">
                                    <img src={user?.avatar} />
                                </div>
                            </div>
                        </div>
                        <div className="stat-title text-white">{user?.login}</div>
                        <div className="stat-desc">{user?.full_name}</div>
                    </div>

                    <div className="stat">
                        <div className="text-primary flex justify-center text-3xl">
                           <IoGameController/>
                        </div>
                        <div className="stat-title text-center">Games Played</div>
                        <div className="stat-value text-primary text-center">{matchs?.Total}</div>
                    </div>

                    <div className="stat">
                        <div className="text-secondary flex justify-center text-3xl">
                            <BsTrophyFill/>
                        </div>
                        <div className="stat-title text-center">Total Wins</div>
                        <div className="stat-value text-secondary text-center">{matchs?.Wins}</div>
                    </div>
                    <div className="stat">
                        <div className="text-secondary flex justify-center text-3xl">
                            <FaAward/>
                        </div>
                        <div className="stat-title text-center">W/L Ratio</div>
                        <div className="stat-value text-secondary text-center">%{matchs?.Ratio.toFixed(2)}</div>
                    </div>
                </div>
                <MatchHistory id={router.query.id} limit={100} />
            </div>


        </div>

    )



}
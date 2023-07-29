import { useContext, useEffect, useState } from "react";
import axios from "@/lib/axios";
import { useAuthContext } from "@/auth/AuthContext";

export interface MatchInfo {
  Total: number;
  Wins: number;
  Loses: number;
  Ratio: number;
}

export function matchInfo(user: string, matchHistory: any[]) {
  if (!matchHistory) return;

  const total = matchHistory.length;
  let wins = 0;
  let loses = 0;

  for (let i = 0; i < total; i++) {
    if (user == matchHistory[i].player1.full_name) {
      if (matchHistory[i].score1 > matchHistory[i].score2) wins++;
      else if (matchHistory[i].score2 > matchHistory[i].score1) loses++;
    } else {
      if (matchHistory[i].score2 > matchHistory[i].score1) wins++;
      else if (matchHistory[i].score1 > matchHistory[i].score2) loses++;
    }
  }

  const ret = {
    Total: total,
    Wins: wins,
    Loses: loses,
    Ratio: loses ? wins / loses : wins,
  }

  return ret;
}

export default function MatchHistory(props: any): any {
  const { user } = useAuthContext();

  const [matchHistory, setMatchHistory]: any[] = useState();

  useEffect(() => {
    axios
      .get(`/user/match-history/${props.id ?? user?.id}/${props.limit ?? 5}`)
      .then((res) => setMatchHistory(res.data));
  }, []);

  return (
    <div className="w-full">
      <div className="py-2.5">
        <label>Match History</label>
      </div>
      <div className="overflow-x-auto overflow-y-auto w-full h-96">
        <table className="table w-full">
          <thead>
            <tr className="text-center">
              <th>Username</th>
              <th>Score</th>
              <th>Enemy</th>
            </tr>
          </thead>
          <tbody>
            {matchHistory &&
              matchHistory.map((match: any) => (
                <tr key={match.id}>
                  <td className="text-center">
                    <div className="flex items-center space-x-3">
                      <div className="avatar">
                        <div className="mask mask-squircle w-12 h-12">
                          <img
                            src={match.player1.avatar}
                            alt="Avatar Tailwind CSS Component"
                          />
                        </div>
                      </div>
                      <div>
                        <div className="font-bold">
                          {match.player1.full_name}
                        </div>
                        <div className="text-sm opacity-50">China</div>
                      </div>
                    </div>
                  </td>
                  <td className="text-center">{match.score1}</td>
                  <td>
                    <div className="flex items-center space-x-3">
                      <div>
                        <div className="font-bold">
                          {match.player2.full_name}
                        </div>
                        <div className="text-sm opacity-50">Russia</div>
                      </div>
                      <div className="avatar">
                        <div className="mask mask-squircle w-12 h-12">
                          <img
                            src={match.player2.avatar}
                            alt="Avatar Tailwind CSS Component"
                          />
                        </div>
                      </div>
                    </div>
                  </td>
                </tr>
              ))}
          </tbody>
        </table>
      </div>
    </div>
  );
}

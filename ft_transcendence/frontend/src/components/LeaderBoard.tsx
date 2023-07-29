import {useEffect, useState} from "react";
import axios from "@/lib/axios";

export default function LeaderBoard() {

	const [leaders, setLeaders] : any = useState() ;

	useEffect(() => {
		axios.get("/user/leaders").then((res) => setLeaders(res.data));
	}, []);

	return (
		<>
			<div className="overflow-x-auto w-full">
				<div className="py-2.5">
					<label>Leaderboard</label>
				</div>
				<table className="table w-full">
					<thead>
					<tr className="text-center">
						<th>Full Name</th>
						<th>Total Wins</th>
					</tr>
					</thead>
					<tbody>
					{leaders && leaders.map((user: any, index: number) => (
						<tr key={index}>
							<td>
								<div className="flex items-center space-x-3">
									<div className="avatar">
										<div className="mask mask-squircle w-12 h-12">
											<img src={user.avatar}
												 alt="Avatar Tailwind CSS Component"/>
										</div>
									</div>
									<div>
										<div className="font-bold">{user.full_name}</div>
									</div>
								</div>
							</td>
							<td className="text-center">
								{user.score}
							</td>
						</tr>
					))}
					</tbody>
				</table>
			</div>
		</>
	);
}
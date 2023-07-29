import React, {useEffect, useState} from "react";
import axios from "@/lib/axios";
import toast from "react-hot-toast";

export default function PublicChannels({getChannels}: any) {

	const [channels, setChannels] = useState<any[]>([]);

	const handleJoinChannel = (channelId: number) => {
		axios.post('/channel/join/' + channelId).then(() => {
			toast.success("joined channel!");
			getPublicChannels();
			getChannels();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const getPublicChannels = () => {
		axios.get('/channel/public').then((res) => {
			setChannels(res.data);
		});
	}

	useEffect(() => {
		getPublicChannels();
	}, []);


	return (
		<>
			<input type="checkbox" id="openPublicChannelsModal" className="modal-toggle"/>
			<div className="modal">
				<div className="modal-box relative">
					<label htmlFor="openPublicChannelsModal"
						   className="btn btn-sm btn-circle absolute right-2 top-2">✕</label>
					<h3 className="text-lg font-bold text-center mb-4">
						Public Channels
					</h3>
					<div className="bg-neutral rounded-2xl p-10">
						<ul tabIndex={0}
							className="dropdown-content menu p-2 shadow bg-base-100 rounded-box z-40 w-full">
							{channels.map((channel, index) => (
								<li key={index} className="w-full h-auto cursor-pointer">
									<div className="flex items-center justify-between">
										<div className="flex items-center gap-x-3">
											<div>
											<span>
												{channel.name}
											</span>
											</div>
										</div>
										<div>
											<button className="btn btn-primary"
													onClick={() => handleJoinChannel(channel.id)}
											>
												Join
											</button>
										</div>
									</div>
								</li>
							))}
						</ul>
					</div>
				</div>
			</div>
		</>
	);
}

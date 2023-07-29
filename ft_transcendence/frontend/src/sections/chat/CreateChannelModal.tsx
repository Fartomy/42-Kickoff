import React, {useState} from "react";
import axios from "@/lib/axios";
import toast from "react-hot-toast";

export default function CreateChannelModal({getChannels}: any) {

	const [channelName, setChannelName] = useState('');

	const handleCreateChannel = () => {
		axios.post('/channel', {
			name: channelName
		}).then(() => {
			getChannels();
			setChannelName('');
			toast.success("Channel created!");
		}).catch((err) => {
			toast.error("An error occurred!");
		});
	}

	return (
		<>
			<input type="checkbox" id="openCreateChannel" className="modal-toggle"/>
			<div className="modal">
				<div className="modal-box relative">
					<label htmlFor="openCreateChannel"
						   className="btn btn-sm btn-circle absolute right-2 top-2">✕</label>
					<h3 className="text-lg font-bold text-center">
						Create Channel
					</h3>
					<div className="py-4">
						<div className="form-control">
							<label className="label">
								Channel Name
							</label>
							<label className="input-group input-group-vertical">
								<input type="text" className="input input-bordered w-full"
									   onChange={(e) => setChannelName(e.target.value)}/>
							</label>
						</div>
						<div className="mt-6 flex flex-col">
							<button className="btn btn-primary" onClick={handleCreateChannel}>
								Create Channel
							</button>
						</div>
					</div>
				</div>
			</div>
		</>
	)
}

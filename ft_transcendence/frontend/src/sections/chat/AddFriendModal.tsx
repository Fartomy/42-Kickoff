import React, {useEffect, useState} from "react";
import axios from "@/lib/axios";
import toast from "react-hot-toast";

export default function AddFriendModal({getFriends}: any) {

	const [activeTab, setActiveTab] = useState('non-friends');
	const [nonFriends, setNonFriends] = useState([]);
	const [friendRequests, setFriendRequests] = useState([]);

	const handleAddFriend = (friendId: number) => {
		axios.post('/friend', {
			friend: friendId
		}).then(() => {
			toast.success("Friend request sent!");
			getFriends();
			getNonFriends();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const handleAcceptFriend = (friendId: number) => {
		axios.put('/friend/accept/' + friendId).then(() => {
			toast.success("Friend request accepted!");
			getFriends();
			getFriendRequests();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const handleRejectFriend = (friendId: number) => {
		axios.put('/friend/reject/' + friendId).then(() => {
			toast.success("Friend request rejected!");
			getFriends();
			getFriendRequests();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const getNonFriends = () => {
		axios.get('/friend/non-friends').then((res) => {
			setNonFriends(res.data);
		});
	}

	const getFriendRequests = () => {
		axios.get('/friend/requests').then((res) => {
			setFriendRequests(res.data);
		});
	}

	useEffect(() => {
		getNonFriends();
		getFriendRequests();
	}, []);

	return (
		<>
			<input type="checkbox" id="openAddFriendModal" className="modal-toggle"/>
			<div className="modal">
				<div className="modal-box w-11/12 max-w-5xl">
					<label htmlFor="openAddFriendModal"
						   className="btn btn-sm btn-circle absolute right-2 top-2">✕</label>
					<div className="flex justify-center mb-5">
						<div className="tabs tabs-boxed mt-3 w-80 justify-center">
							<a className={activeTab === 'non-friends' ? "tab tab-active" : "tab"}
							   onClick={() => setActiveTab('non-friends')}>Friends</a>
							<a className={activeTab === 'requests' ? "tab tab-active" : "tab"}
							   onClick={() => setActiveTab('requests')}>Friend Requests ({friendRequests?.length}) </a>
						</div>
					</div>
					<div className="bg-neutral rounded-2xl p-10">
						{activeTab === 'non-friends' ? (
							nonFriends.map((nonFriend: any, index: any) => (
								<li key={index} className="w-full h-auto cursor-pointer">
									<div className="flex items-center justify-between">
										<div className="flex items-center gap-x-3">
											<div className="avatar">
												<div className="w-16 rounded-full">
													<img src={nonFriend.avatar} alt={nonFriend.full_name}/>
												</div>
											</div>
											<div>
											<span>
												{nonFriend.full_name}
											</span>
											</div>
										</div>
										<div>
											<button className="btn btn-primary"
													onClick={() => handleAddFriend(nonFriend.id)}>
												Add Friend
											</button>
										</div>
									</div>
								</li>
							))
						) : friendRequests.map((request: any, index: any) => (
							<li key={index} className="w-full h-auto cursor-pointer">
								<div className="flex items-center justify-between">
									<div className="flex items-center justify-between gap-x-3 w-full">
										<div className="flex items-center gap-x-5">
											<div className="avatar">
												<div className="w-16 rounded-full">
													<img src={request.user.avatar} alt={request.user.full_name}/>
												</div>
											</div>
												<span>
													{request.user.full_name}
												</span>
										</div>
										<div>
											<button className="btn btn-primary" onClick={() => handleAcceptFriend(request.id)}>
												Accept
											</button>

											<button className="btn btn-ghost" onClick={() => handleRejectFriend(request.id)}>
												Reject
											</button>
										</div>
									</div>
								</div>
							</li>
						))}
					</div>
				</div>
			</div>
		</>
	);
}

import DashboardLayout from "@/layouts/DashboardLayout";
import React, {useEffect, useRef, useState} from "react";
import {AdjustmentsHorizontalIcon, LockClosedIcon} from "@heroicons/react/20/solid";
import {io} from "socket.io-client";
import axios from "@/lib/axios";
import ChannelSettingModal from "@/sections/chat/ChannelSettingModal";
import CreateChannelModal from "@/sections/chat/CreateChannelModal";
import AddFriendModal from "@/sections/chat/AddFriendModal";
import toast from "react-hot-toast";
import {BiRefresh} from "react-icons/bi";
import PublicChannels from "@/sections/chat/PublicChannels";
import {v4 as uuidv4} from 'uuid';
import Link from "next/link";

Chat.getLayout = (page: any) => <DashboardLayout>{page}</DashboardLayout>

interface IMessage {
	avatar: string;
	name: string;
	message: string;
	ownerId: number;
	recieverId: number;
}

interface IChannelMessage {
	channelId: number;
	userId: number;
	avatar: string;
	name: string;
	message: string;
}

export default function Chat() {

	const [activeTab, setActiveTab] = useState('friends');
	const [directMessages, setDirectMessages] = useState<IMessage[]>([]);
	const [groupDirectMessages, setGroupDirectMessages] = useState<any[]>([]);
	const [channelsMessages, setChannelsMessages] = useState<IChannelMessage[]>([]);
	const [profile, setProfile] = useState<any>({});
	const [friends, setFriends] = useState<any[]>([]);
	const [selectedFriend, setSelectedFriend] = useState<any>({});
	const [channels, setChannels] = useState<any[]>([]);
	const [channel, setChannel] = useState<any>({});
	const [selectedChannel, setSelectedChannel] = useState<number>(0);
	const chatRef = useRef<HTMLDivElement>(null);
	const [channelPassword, setChannelPassword] = useState<string>('');

	const socketUrl: string = process.env.NEXT_PUBLIC_SOCKET_URL + "/chat" || '';

	let socket: any = useRef<any>(null);

	const enterKeyPress = (e: any) => {
		if (e.key === 'Enter') {
			if (activeTab === 'friends') {
				const message: IMessage = {
					avatar: profile?.avatar,
					name: profile?.full_name,
					message: e.target.value,
					ownerId: profile?.id,
					recieverId: selectedFriend.id
				}

				socket.current.emit('message', message);

				setDirectMessages((prevMessages) => [...prevMessages, message]);

			} else {
				const message: IChannelMessage = {
					channelId: selectedChannel,
					userId: profile?.id,
					avatar: profile?.avatar,
					name: profile?.full_name,
					message: e.target.value,
				}

				if (channel.is_muted) {
					toast.error("You are muted!");
				} else {
					socket.current.emit('channel-message', message);
				}
			}
			e.target.value = '';
		}
	}

	const handleSendGameRequest = () => {
		const message: IMessage = {
			avatar: profile?.avatar,
			name: profile?.full_name,
			message: `<a class="underline text-red-400" href="/game/game?invite=${uuidv4()}">Play Game</a>`,
			ownerId: profile?.id,
			recieverId: selectedFriend.id
		}

		socket.current.emit('message', message);
		setDirectMessages((prevMessages) => [...prevMessages, message]);

	}


	// Direct Messages
	const handleSelectFriend = (friend: any) => {
		setSelectedFriend(friend);
		//setDirectMessages([]);
	}

	const handleMessages = (message: IMessage) => {
		setDirectMessages((prevMessages) => [...prevMessages, message]);
	}

	const handleBanFriend = (friendId: number) => {
		axios.put('/friend/' + friendId, {
			is_banned: true,
		}).then(() => {
			toast.success("Friend banned!");
			setFriends(friends.filter((friend) => friend.id !== friendId));
		}).catch((err) => {
			toast.error("An error occurred!");
			console.log(err);
		});
	}


	// Channels Messages
	const handleChannelMessages = (message: IChannelMessage) => {
		console.log("message", message);
		setChannelsMessages((prevMessages) => [...prevMessages, message]);
	}

	const handleJoinChannel = (channelId: number, channelType: string) => {
		if (selectedChannel) {
			socket.current.emit('leave-channel', selectedChannel);
		}
		setSelectedChannel(channelId);

		if (channelType === 'protected' && selectedChannel !== channelId) {
			window.chat_password_modal.showModal();
			return;
		}

		socket.current.emit('join-channel', channelId);
		setChannelsMessages([]);
	}

	const handleJoinProtectedChannel = async () => {
		const check = await axios.post('channel/check-password', {
			id: selectedChannel,
			password: channelPassword
		})

		if (!check.data) {
			toast.error("Wrong password!");
			return;
		}

		socket.current.emit('join-channel', {
			channelId: selectedChannel,
			channelPassword
		})

		setChannelPassword('');

		window.chat_password_modal.close();
		setChannelsMessages([]);
	}

	const handleDeleteChannel = (channelId: number) => {
		axios.delete('/channel/' + channelId).then((res) => {
			toast.success("Channel deleted!");
			setChannels(channels.filter((channel) => channel.channel.id !== channelId));
		}).catch((err) => {
			toast.error("An error occurred!");
			console.log(err);
		});
	}

	const handleLeaveChannel = (channelId: number) => {
		axios.post('/channel/leave/' + channelId).then((res) => {
			toast.success("Channel left!");
			setChannels(channels.filter((channel) => channel.channel.id !== channelId));
		});
	}

	const getFriends = () => {
		axios.get('/friend', {
			params: {
				status: 'accepted'
			}
		}).then((res) => {
			setFriends(res.data);
		}).catch((err) => {
			console.log(err);
		});
	}

	const getChannels = () => {
		axios.get('/channel').then((res) => {
			setChannels(res.data);
		}).catch((err) => {
			console.log(err);
		});
	}

	const getChannel = (userId: number) => {
		axios.get('/channel/member/' + selectedChannel, {
			params: {
				userId
			}
		}).then((res) => {
			setChannel(res.data);
		});
	}

	const scrollToBottom = () => {
		if (chatRef.current) {
			chatRef.current.scrollTop = chatRef.current.scrollHeight;
		}
	};

	useEffect(() => {
		socket.current = io(socketUrl);

		socket.current.on("connect", () => {
			console.log("Connected to socket server!");
		});

		socket.current.on("message", handleMessages);

		socket.current.on("channel-message", handleChannelMessages);

		socket.onmessage = (e: any) => {
			console.log(e);
		}

		socket.current.on("disconnect", () => {
			console.log("Disconnected from socket server!");
		});

		axios.get('/auth/my-account').then((res) => {
			setProfile(res.data);
			socket.current.emit('connect-user', res.data.id);
		})

		getFriends();
		getChannels();

		return () => {
			socket.current.disconnect();
		};
	}, []);

	useEffect(() => {
		scrollToBottom();
	}, [directMessages, channelsMessages]);

	useEffect(() => {
		if (profile.id) {
			getChannel(profile?.id);
		}
	}, [profile, selectedChannel]);

	return (
		<>
			<div className="flex md:flex-row flex-col gap-5 md:h-[calc(100vh-120px)] h-screen">
				<div
					className="flex flex-col md:w-3/12 md:h-full h-1/2 w-full items-center justify-center bg-neutral rounded-2xl border border-solid border-primary">
					<div className="flex w-full p-2 gap-x-2">
						<div className="w-full">
							<label htmlFor="openCreateChannel" className="btn btn-outline w-full">
								Create Channel
							</label>
						</div>
						<div className="w-full">
							<label htmlFor="openAddFriendModal" className="btn btn-outline w-full">
								Add Friend
							</label>
						</div>
						<div className="w-full">
							<label htmlFor="openPublicChannelsModal" className="btn btn-outline w-full">
								Public Channels
							</label>
						</div>
					</div>
					<div className="tabs tabs-boxed mt-3">
						<a className={activeTab === 'friends' ? "tab tab-active" : "tab"}
						   onClick={() => setActiveTab('friends')}>Friends</a>
						<a className={activeTab === 'channels' ? "tab tab-active" : "tab"}
						   onClick={() => setActiveTab('channels')}>Channels</a>
					</div>
					<div className="w-full mt-2 p-4">
						<button className="btn btn-primary w-full" onClick={() => {
							getFriends()
							getChannels()
						}}>
							<BiRefresh className="w-6 h-6"/>
						</button>
					</div>
					<div className="md:w-80 w-full h-screen bg-neutral text-base-content overflow-y-auto">
						<ul className="flex flex-row p-4 menu rounded-2xl">
							{activeTab === 'friends' && friends.map((friend, index) => (
								<li key={index}
									className={selectedFriend.id === friend.friend.id ? 'w-full h-auto cursor-pointer bg-primary text-white rounded-lg' : 'w-full h-auto cursor-pointer rounded-lg'}
									onClick={() => handleSelectFriend(friend.friend)}>
									<div className="flex items-center justify-between">
										<div className="flex items-center gap-x-3">
											<div
												className={friend.friend.is_online ? 'avatar online' : 'avatar offline'}>
												<div className="w-12 rounded-full">
													<img src={friend.friend.avatar}/>
												</div>
											</div>
											<div>
											<span>
												{friend.friend.full_name} {friend.friend.is_gamer && (<p>
													<span className="text-xs font-bold"> (In Game)</span>
												</p>)}
											</span>
											</div>
										</div>
										<div className="dropdown dropdown-end">
											<label tabIndex={0} className="btn">
												<AdjustmentsHorizontalIcon className="w-4"/>
											</label>
											<ul tabIndex={0}
												className="dropdown-content menu p-2 shadow bg-base-100 rounded-box z-40 w-52">
												<li>
													<button onClick={() => handleBanFriend(friend.id)}>Banned</button>
													<Link href={`/profile/${friend.friend.id}`}>
														Profile
													</Link>
												</li>
											</ul>
										</div>
									</div>
								</li>
							))}

							{activeTab === 'channels' && channels.map((channel, index) => (
								<li key={index}
									className={selectedChannel === channel.channel.id ? 'w-full cursor-pointer bg-primary text-white rounded-lg' : 'w-full cursor-pointer rounded-lg'}
									onClick={() => handleJoinChannel(channel.channel.id, channel.channel.type)}>
									<div className="flex items-center justify-between">
										<div className="flex gap-x-4">
											<span>
												{channel.channel.name}
											</span>
											<span>
												{channel.channel.type === 'protected' &&
													<LockClosedIcon className="w-4 h-4"/>}
											</span>
										</div>
										<div className="dropdown dropdown-end">
											<label tabIndex={0} className="btn">
												<AdjustmentsHorizontalIcon className="w-4"/>
											</label>
											<ul tabIndex={0}
												className="dropdown-content menu p-2 shadow bg-base-100 rounded-box z-40  w-52">
												<li>
													{(channel.is_owner || channel.is_admin) && (
														<label htmlFor="openModal">Setting</label>
													)}
													{channel.is_owner && (
														<label
															onClick={() => handleDeleteChannel(channel.channel.id)}>Delete</label>
													)}
													<label
														onClick={() => handleLeaveChannel(channel.channel.id)}>Leave</label>
												</li>
											</ul>
										</div>
									</div>
								</li>
							))}
						</ul>
					</div>
				</div>
				{activeTab === 'friends' ? (
					<div className="card w-full bg-neutral shadow-xl h-[400px] md:h-full">
						<div ref={chatRef} className="card-body overflow-y-auto">
							<div className="w-full flex justify-between bg-primary p-3 rounded-3xl">
								<h2 className="card-title text-white">Chat</h2>
								{Object.keys(selectedFriend).length > 0 && (
									<button className="btn btn-primary" onClick={handleSendGameRequest}>Send Game
										Request</button>)}
							</div>
							{Object.keys(selectedFriend).length ? (
								<div>
									{directMessages.map((direct: IMessage, index: number): React.ReactElement => (
										<div key={index}>
											{direct.ownerId === selectedFriend.id && (
												<div
													className={direct.recieverId !== profile.id ? "chat chat-end" : "chat chat-start"}>
													<div className="chat-image avatar">
														<div className="w-10 rounded-full">
															<img src={direct.avatar}/>
														</div>
													</div>
													<div className="chat-header">
														{direct.name}
													</div>
													<div className="bg-green-950 chat-bubble"
														 dangerouslySetInnerHTML={{__html: direct.message}}/>
												</div>
											)}

											{direct.recieverId === selectedFriend.id && (
												<div
													className={direct.recieverId !== profile.id ? "chat chat-end" : "chat chat-start"}>
													<div className="chat-image avatar">
														<div className="w-10 rounded-full">
															<img src={direct.avatar}/>
														</div>
													</div>
													<div className="chat-header">
														{direct.name}
													</div>
													<div className="bg-green-950 chat-bubble"
														 dangerouslySetInnerHTML={{__html: direct.message}}/>
												</div>
											)}
										</div>
									))}
								</div>
							) : (
								<div className="flex h-full mx-auto items-center text-2xl">
									Please select a friend or channel.
								</div>
							)}
						</div>
						<div className="card-footer">
							<div className="form-control">
								<input type="text" disabled={Object.keys(selectedFriend).length === 0}
									   onKeyPress={enterKeyPress} placeholder="Type here"
									   className="mt-10 input w-full input-primary"/>
							</div>
						</div>
					</div>
				) : (
					<div className="card w-full bg-neutral shadow-xl h-[400px] md:h-full">
						<div ref={chatRef} className="card-body overflow-y-auto">
							<h2 className="card-title">Chat</h2>
							{selectedChannel ? (
								<div>
									{channelsMessages.map((channelMessage: IChannelMessage, index: number): React.ReactElement => (
										<div
											className={channelMessage.userId === profile.id ? "chat chat-end" : "chat chat-start"}
											key={index}>
											<div className="chat-image avatar">
												<div className="w-10 rounded-full">
													<img src={channelMessage.avatar}/>
												</div>
											</div>
											<div className="chat-header">
												{channelMessage.name}
											</div>
											<div className="bg-green-950 chat-bubble">{channelMessage.message}</div>
										</div>
									))}
								</div>
							) : (
								<div className="flex h-full mx-auto items-center text-2xl">
									Please select a friend or channel.
								</div>
							)}
						</div>
						<div className="card-footer">
							<div className="form-control">
								<input
									type="text"
									disabled={!selectedChannel}
									onKeyPress={enterKeyPress}
									placeholder="Type here"
									className="mt-10 input w-full input-primary"
								/>
							</div>
						</div>
					</div>
				)}
			</div>

			{selectedChannel !== 0 &&
				<ChannelSettingModal channelId={selectedChannel} friends={friends} profile={profile}/>}
			<CreateChannelModal getChannels={getChannels}/>
			<AddFriendModal getFriends={getFriends}/>
			<PublicChannels getChannels={getChannels}/>

			<dialog id="chat_password_modal" className="modal">
				<form method="dialog" className="modal-box">
					<h3 className="font-bold text-lg">Channel Password</h3>
					<div className="form-control mt-5">
						<input type="password" placeholder="Password" value={channelPassword}
							   onChange={e => setChannelPassword(e.target.value)}
							   className="input input-bordered"/>
					</div>

					<div className="modal-action">
						<button className="btn" type="button" onClick={handleJoinProtectedChannel}>Submit</button>
					</div>
				</form>
			</dialog>
		</>
	);
}

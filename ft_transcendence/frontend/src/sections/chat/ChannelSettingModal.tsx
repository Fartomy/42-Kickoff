import {AdjustmentsHorizontalIcon} from "@heroicons/react/20/solid";
import React, {useEffect, useState} from "react";
import axios from "@/lib/axios";
import toast from "react-hot-toast";

const categories = ['public', 'protected', 'private'];

export default function ChannelSettingModal({friends, channelId, profile}: any) {

	const [channelCategory, setChannelCategory] = useState<string>('');
	const [channelPassword, setChannelPassword] = useState<string>('');
	const [channelNonMembers, setChannelNonMembers] = useState<any[]>([]);
	const [channelMembers, setChannelMembers] = useState<any[]>([]);
	const [me, setMe] = useState<any>({});
	const [activeTab, setActiveTab] = useState('members');

	const handleChangeChannelCategory = (e: any) => {
		setChannelCategory(e.target.value);
	}

	const handleChangeChannelPassword = (e: any) => {
		setChannelPassword(e.target.value);
	}

	const handleOnSubmitChannelCategory = () => {
		axios.put('/channel/' + channelId, {
			type: channelCategory,
			password: channelPassword
		}).then(() => {
			toast.success("Channel category updated!");
		}).catch((err) => {
			toast.error("An error occurred!");
		});
	}


	const handleMemberMuted = (userId: number) => {
		axios.put('/channel/member/' + channelId, {is_muted: true}, {
			params: {
				userId
			},
		}).then(() => {
			toast.success("Member muted!");
			getChannelNonMembers();
			getChannelMembers();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const handleAddMember = (userId: number) => {
		axios.post('/channel/add-member/' + channelId, {
			userId
		}).then(() => {
			toast.success("Member added!");
			getChannelNonMembers();
			getChannelMembers();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const handleMemberBanned = (userId: number) => {
		axios.put('/channel/member/' + channelId, {is_banned: true},{
			params: {
				userId
			}
		}).then(() => {
			toast.success("Member banned!");
			getChannelNonMembers();
			getChannelMembers();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const handleAssignAdmin = (userId: number) => {
		axios.put('/channel/assign-admin/' + channelId, {
			userId
		}).then(() => {
			toast.success("Admin assigned!");
			getChannelNonMembers();
			getChannelMembers();
		}).catch(() => {
			toast.error("An error occurred!");
		});
	}

	const getChannelNonMembers = () => {
		axios.get('/channel/non-members/' + channelId).then((res) => {
			setChannelNonMembers(res.data);
		});
	}

	const getChannelMembers = () => {
		axios.get('/channel/members/' + channelId).then((res) => {
			setChannelMembers(res.data);
		});
	}

	const getChannel = () => {
		axios.get('/channel/' + channelId).then((res) => {
			setChannelCategory(res.data.type);
		});
	}

	const getMe = () => {
		axios.get('/channel/member/' + channelId, {
			params: {
				userId: profile?.id,
			}
		}).then((res) => {
			setMe(res.data);
		});
	}

	useEffect(() => {
		getChannel();
		getChannelMembers();
		getChannelNonMembers();
		getMe();
	}, [friends, channelId]);

	useEffect(() => {
		if (channelCategory !== 'protected') {
			setChannelPassword('');
		}
	}, [channelCategory]);


	return (
		<>
			<input type="checkbox" id="openModal" className="modal-toggle"/>
			<div className="modal">
				<div className="modal-box w-11/12 max-w-5xl">
					<label htmlFor="openModal" className="btn btn-sm btn-circle absolute right-2 top-2">✕</label>
					<h3 className="font-bold text-lg">Channel Setting</h3>
					<div className="divider"></div>
					<div className="w-9/12 mx-auto">
						{me?.is_owner && (
							<div className="w-full">
								<div className="form-control">
									<label className="label">Channel Category</label>
									<div className="input-group w-full">
										<select className="select select-bordered w-full" value={channelCategory}
												onChange={handleChangeChannelCategory}>
											{categories.map((category, index) => (
												<option key={index} value={category}>{category}</option>
											))}
										</select>
										<button className="btn" onClick={handleOnSubmitChannelCategory}>Submit</button>
									</div>
								</div>
								{channelCategory === 'protected' && (
									<div className="form-control">
										<label className="label">Password</label>
										<input type="password" className="input bg-neutral"
											   onChange={handleChangeChannelPassword}/>
									</div>
								)}
							</div>
						)}

						<div className="divider"></div>
						<div className="w-full bg-neutral p-6 rounded-lg">
							<div className="flex justify-center tabs tabs-boxed mb-10">
								<a className={activeTab === 'members' ? "tab tab-active" : "tab"}
								   onClick={() => setActiveTab('members')}>Members</a>
								<a className={activeTab === 'add-new-member' ? "tab tab-active" : "tab"}
								   onClick={() => setActiveTab('add-new-member')}>Add New Member</a>
							</div>

							{activeTab === 'members' ? (
								channelMembers.map((channelMember: any, index: any) => (
									<li key={index} className="w-full h-auto cursor-pointer">
										<div className="flex items-center justify-between">
											<div className="flex items-center gap-x-3">
												<div className="avatar">
													<div className="w-12 rounded-full">
														<img src={channelMember.user.avatar}/>
													</div>
												</div>
												<div>
													<span>
														{channelMember.user.full_name}
														{}
														{channelMember.is_owner && (
															<span className="text-xs font-bold"> (Owner)</span>
														)}

														{channelMember.is_admin && (
															<span className="text-xs font-bold"> (Admin)</span>
														)}
													</span>
												</div>
											</div>
											{(me.is_owner || me.is_admin) && (
												<div className="dropdown dropdown-end">
													{!channelMember.is_owner && (
														<>
															<label tabIndex={0} className="btn">
																<AdjustmentsHorizontalIcon className="w-4"/>
															</label>
															<ul tabIndex={0}
																className="dropdown-content menu p-2 shadow bg-base-100 rounded-box z-40 w-52">
																{(me?.is_owner && !channelMember.is_admin) && (
																	<li><a
																		onClick={() => handleAssignAdmin(channelMember.user.id)}>Assign
																		Admin</a></li>
																)}
																{((me?.is_owner || me?.is_admin) && !channelMember.is_owner) && (
																	<>
																		<li><a onClick={() => handleMemberBanned(channelMember.user.id)}>Banned</a></li>
																		<li><a onClick={() => handleMemberMuted(channelMember.user.id)}>Mute</a></li>
																	</>
																)}
															</ul>
														</>
													)}
												</div>
											)}
										</div>
									</li>
								))
							) : (
								channelNonMembers.map((nonMember: any, index: any) => (
									<li key={index} className="w-full h-auto cursor-pointer">
										<div className="flex items-center justify-between">
											<div className="flex items-center gap-x-3">
												<div className="avatar">
													<div className="w-12 rounded-full">
														<img src={nonMember.avatar}/>
													</div>
												</div>
												<div>
													<span>
														{nonMember.full_name}
													</span>
												</div>
											</div>
											<div className="dropdown dropdown-end">
												<button className="btn btn-primary"
														onClick={() => handleAddMember(nonMember.id)}>
													Add to Channel
												</button>
											</div>
										</div>
									</li>
								))
							)}

						</div>
					</div>
				</div>
			</div>
		</>
	);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:34:49 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:34:50 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Commands.hpp"

int help(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
	std::string message;

	(void)usr;
	(void)data;
	message = "[-* FT_IRC COMMAND LIST *-]\nJOIN: Join a any channel [USAGE] -> JOIN #wow\n"
			  "PRIVMSG: Send message to any user or channel -> PRIVMSG nickName/#chnlName :msg\n"
			  "KICK: Kick a user in your channel -> KICK #chnlName nickname\n"
			  "NICK: Change a nickname -> NICK newNickName\n"
			  "QUIT: Disconnect from server -> QUIT q\n";
	SendMessage(message, pfd[id].fd);

	return 0;
}
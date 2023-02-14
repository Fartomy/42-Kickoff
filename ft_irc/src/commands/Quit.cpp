/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:35:33 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:35:34 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Commands.hpp"
#include "../../inc/ircserv.hpp"

int quit(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
	std::string message;

	(void)usr;
	(void)data;
	message = "[FT_IRC]-/BYE.. :(\r\n";
	SendMessage(message, pfd[id].fd);
	close(pfd[id].fd);

	return 0;
}
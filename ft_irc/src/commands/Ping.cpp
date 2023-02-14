/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:35:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:35:20 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Commands.hpp"

int ping(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
    std::string message;

    (void)usr;
    (void)data;
    message = ":ircserv PONG Ping request received by [FT_IRC]\r\n";
    SendMessage(message, pfd[id].fd);
    return 0;
}

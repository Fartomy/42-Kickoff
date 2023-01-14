/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:24:42 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/01/04 10:33:28 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_HPP
#define IRC_HPP

# define RESET "\e[0m"

# define BLACK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLUE "\e[1;34m"
# define MAGEN "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"

#include "../inc/Client.hpp"
#include "../inc/Server.hpp"
#include "../inc/Commands.hpp"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <poll.h>
#include <errno.h>

class Client;
class Server;

using std::cout;
using std::cerr;
using std::endl;
using std::string;

extern string g_PASS;
int sockAttr( struct sockaddr_in *servSock, short int port);
void clientDisconnecter( std::vector<struct pollfd> &plFd, std::vector<Client> &usr, sockaddr_in *servSock, int cli );
int clientAdder( std::vector<struct pollfd> &plFd, std::vector<Client> &usr, sockaddr_in *servSock, int servSock_fd );
int clientAuth( std::vector<struct pollfd> &plFd, std::vector<Client> &usr, int cli );

#endif
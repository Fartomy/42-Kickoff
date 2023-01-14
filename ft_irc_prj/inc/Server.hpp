#ifndef SERVER_HPP
#define SERVER_HPP

#include "../inc/ircserv.hpp"
#include "../inc/Client.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <poll.h>

class Client;

using std::string;
using std::exception;

class Server
{
public:
	Server();
	Server( int port, string pass );
	~Server();

	struct sockaddr_in servSock;
	struct WrongPortNumber : public exception
	{
		const char* what() const throw();
	};

	int getPORT( void );
	string getPASS( void );

	int sockStart( void );
	int sockScan( void );

private:
	int PORT;
	string PASS;
	int servSock_fd;
};

#endif
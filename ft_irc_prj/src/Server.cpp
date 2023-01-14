#include "../inc/Server.hpp"

Server::Server(){};

Server::Server( int port, string pass ) : PORT(port), PASS(pass)
{
	if( PORT > 65535 || PORT < 1024 )
		throw WrongPortNumber();
};

const char* Server::WrongPortNumber::what() const throw()
{
	return "Wrong Port Number!";
}

Server::~Server() {};

string Server::getPASS( void ) { return PASS; }

int Server::getPORT( void ) { return PORT; }

int Server::sockStart( void )
{
	memset(&servSock, 0, sizeof(servSock));
	servSock_fd = sockAttr( &servSock, PORT );
	if( servSock_fd == -1 )
		return -1;
	if( fcntl( servSock_fd, F_SETFL, O_NONBLOCK ) == -1 )
	{
		cerr << RED << "[-]Socket could not be set to nonblock" << RESET << endl;
		close(servSock_fd);
		return -1;
	}
	if( listen(servSock_fd, 5) == -1 )
	{
		cerr << RED <<"[-]Socket is not listening!" << RESET << endl;
		close(servSock_fd);
		return -1;
	}
	cout << YLW << "[.]Server Listening..." << RESET << endl;
	return 0;
}

int Server::sockScan( void )
{
	struct pollfd pl;
	std::vector<struct pollfd> plFd;
	std::vector<Client> usr;
	int val;
	unsigned int i;

	pl.fd = servSock_fd;
	pl.events = POLLIN;
	plFd.push_back(pl);
	while (true)
	{
		val = poll(&plFd[0], plFd.size(), -1);
		if( val == 0 )
		{
			cerr << RED << "[-]Time has expired!" << RESET << endl;
			break;
		}
		if( val == -1 )
		{
			cerr << RED << "[-]Error from poll!" << RESET << endl;
			break;
		}
		i = 0;
		while ( i < plFd.size() )
		{
			if (plFd[i].revents == 0)
			{
				i++;
				continue;
			}
			if (plFd[i].revents != POLLIN )
			{
				clientDisconnecter( plFd, usr, &servSock, i );
				continue;
			}
			if( plFd[i].fd == servSock_fd )
			{
				if ( clientAdder(plFd, usr, &servSock, servSock_fd) == -1)
					return -1;
			}
			else
			{
				if ( clientAuth( plFd, usr, i ) == -1 )
				{
					clientDisconnecter( plFd, usr, &servSock, i );
					i--;
				}
			}
			i++;
		}
	}
	return 0;
}
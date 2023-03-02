#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_client
{
	int fd;
	int id;
	int new;
}	t_client;

fd_set sockets, write_sockets, read_sockets;
t_client clients[1024 * 4];

int server_fd;
int client_cnt = 0;
int client_sz = sizeof(clients) / sizeof(*clients);

int ft_err(const char* msg)
{
	write(2, msg, strlen(msg));
	return 1;
}

int get_max_fd()
{
	int max = server_fd;

	for(int i = 0; i < client_sz; i++)
		if(clients[i].fd > max)
			max = clients[i].fd;
	return max;
}

int get_client_id(int fd)
{
	for(int i = 0; i < client_sz; i++)
		if(clients[i].fd == fd)
			return i;
	return -1;
}

int get_free_client()
{
	for(int i = 0; i < client_sz; i++)
		if(clients[i].fd == -1)
			return i;
	return -1;
}

void send_all(const char* msg, int fd)
{
	for(int i = 0; i < client_sz; i++)
		if(clients[i].fd > -1 && clients[i].fd != fd && FD_ISSET(clients[i].fd, &write_sockets))
			send(clients[i].fd, msg, strlen(msg), 0);
}

void client_connect()
{
	int client_id = get_free_client();
	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);
	char buff[256];

	clients[client_id].id = client_cnt++;
	clients[client_id].fd = accept(server_fd, (struct sockaddr *)&cli, &len);
	if(clients[client_id].fd < 0)
	{
		ft_err("Fatal error\n");
		exit(1);
	}
	clients[client_id].new = 1;
	bzero(buff, sizeof(buff));
	sprintf(buff, "server: client %d just arrived\n", clients[client_id].id);
	send_all(buff, -1);
	FD_SET(clients[client_id].fd, &sockets);
}

void client_disconnect(int fd)
{
	int client_id = get_client_id(fd);
	char buff[256];

	bzero(buff, sizeof(buff));
	sprintf(buff, "server: client %d just left\n", clients[client_id].id);
	send_all(buff, -1);
	close(clients[client_id].fd);
	FD_CLR(clients[client_id].fd, &sockets);
	clients[client_id].fd = -1;
}

int main(int ac, char** av)
{
	if( ac != 2 )
		return ( ft_err("Wrong number of arguments\n") );
	struct sockaddr_in servaddr;

	server_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (server_fd == -1)
		return ( ft_err("Fatal error\n") );
	bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		return ( ft_err("Fatal error\n") );
	if (listen(server_fd, 128) != 0)
		return ( ft_err("Fatal error\n") );
	FD_ZERO(&sockets);
	FD_SET(server_fd, &sockets);
	memset(&clients, -1, sizeof(clients));

	while(1)
	{
		read_sockets = write_sockets = sockets;
		int max_fd = get_max_fd() + 1;

		if(select(max_fd, &read_sockets, &write_sockets, NULL, NULL) < 0)
			continue;
		for(int fd = server_fd; fd < max_fd; fd++)
		{
			if(FD_ISSET(fd, &read_sockets))
			{
				if(fd == server_fd)
					client_connect();
				else
				{
					char c;
					if(recv(fd, &c, 1, 0) <= 0)
						client_disconnect(fd);
					else
					{
						int client_id = get_client_id(fd);
						if(clients[client_id].new)
						{
							char buff[256];

							bzero(buff, sizeof(buff));
							sprintf(buff, "client %d: ", clients[client_id].id);
							send_all(buff, fd);
							clients[client_id].new = 0;
						}
						else if(c == '\n')
							clients[client_id].new = 1;
						send_all(&c, fd);
					}
				}
			}
		}
	}
}
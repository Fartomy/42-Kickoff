#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_clients
{
    int     id;
    char    msg[1024];
}   t_clients;

t_clients   clients[1024];
fd_set      write_fds, read_fds, sockets;

int         fd_max = 0, id_next = 0;
char        buff_write[120000], buff_read[120000];

void    ft_err(char* msg)
{
    if(msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error", strlen("Fatal error"));
    write(2, "\n", 1);
    exit(1);
}

void    send_all(int not)
{
    for(int i = 0; i <= fd_max; i++)
        if(FD_ISSET(i, &write_fds) && i != not)
            send(i, buff_write, strlen(buff_write), 0);
}

int main(int ac, char** av)
{
    if(ac != 2)
        ft_err("Wrong number of arguments");

	int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0)
        ft_err(NULL);
    
    FD_ZERO(&sockets);
    bzero(&clients, sizeof(clients));
    fd_max = sockfd;
    FD_SET(sockfd, &sockets);

	struct sockaddr_in servaddr;
	socklen_t len; 
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
        ft_err(NULL);
	if (listen(sockfd, 10) < 0)
        ft_err(NULL);

    while(1)
    {
        read_fds = write_fds = sockets;

        if(select(fd_max + 1, &read_fds, &write_fds, NULL, NULL) < 0)
            continue;
        for(int fd = 0; fd <= fd_max; fd++)
        {
            if(FD_ISSET(fd, &read_fds) && fd == sockfd)
            {
                int connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
                if(connfd < 0)
                    continue;
                fd_max = connfd > fd_max ? connfd : fd_max;
                clients[connfd].id = id_next++;
                FD_SET(connfd, &sockets);
                sprintf(buff_write, "server: client %d just arrived\n", clients[connfd].id);
                send_all(connfd);
                break;
            }
            if(FD_ISSET(fd, &read_fds) && fd != sockfd)
            {
                int res = recv(fd, buff_read, 65536, 0);
                if(res <= 0)
                {
                    sprintf(buff_write, "server: client %d just left\n", clients[fd].id);
                    send_all(fd);
                    FD_CLR(fd, &sockets);
                    close(fd);
                    break;
                }
                else
                {
                    for(int i = 0, j = strlen(clients[fd].msg); i < res; i++, j++)
                    {
                        clients[fd].msg[j] = buff_read[i];
                        if(clients[fd].msg[j] == '\n')
                        {
                            clients[fd].msg[j] = '\0';
                            sprintf(buff_write, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                            send_all(fd);
                            bzero(&clients[fd].msg, sizeof(clients[fd].msg));
                        }
                    }
                    break;
                }
            }
        }
    }
}
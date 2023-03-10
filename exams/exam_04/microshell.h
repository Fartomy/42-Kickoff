#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	ft_putstr_fd2(char *str, char *arg);
int ft_execute(char *argv[], int i, int tmp_fd, char *env[]);


#endif
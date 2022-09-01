/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:41:11 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/01 17:31:58 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rdr_input(int ctrl)
{
	if(ctrl == 0)
	{
		dup2(data.fd, 0);
		close(data.fd);
	}
	else if(ctrl == 1)
	{
		dup2(data.fd2, 0);
		close(data.fd2);
	}
}

void	heredoc_oprt(char *prs, int *fd2)
{
	int pid2;

	pipe(fd2);
	pid2 = fork();
	if (pid2 > 0)
	{
		close(fd2[1]);
		wait(NULL);
		dup2(fd2[0], 0);
		close(fd2[0]);
	}
	if (pid2 == 0)
	{
		char *str;
		
		signal(SIGINT, heredc_ctrl_c);
		while (1)
		{
			str = readline(">_ ");
			if (ft_strcmp(prs, str) == 0)
				break;
			str = ft_strjoin(str, "\n");
			write(fd2[1], str, ft_strlen(str));
		}
		exit(0);
	}
}

static void rdr_runner_for_first_arg(char **parse, int x)
{
	int pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (ft_strcmp(parse[x - 1], ">") == 0)
		{
			if(ft_strncmp(parse[0], "<<", 2) == 0)
			{
				int fd2[2];
				heredoc_oprt(parse[1], fd2);
			}
			else if(ft_strcmp(parse[0], "<") == 0)
				rdr_input(1);
			dup2(data.fd, 1);
			close(data.fd);
		}
		else if (ft_strcmp(parse[x - 1], "<") == 0)
		{
			dup2(data.fd, 0);
			close(data.fd);
		}
		else if (ft_strncmp(parse[x - 1], ">>", 2) == 0)
		{
			if(ft_strncmp(parse[0], "<<", 2) == 0)
			{
				int fd2[2];
				heredoc_oprt(parse[1], fd2);
			}
			else if(ft_strcmp(parse[0], "<") == 0)
				rdr_input(1);
			dup2(data.fd, 1);
			close(data.fd);
		}
		else if (ft_strncmp(parse[x - 1], "<<", 2) == 0)
		{
			int fd2[2];
			heredoc_oprt(parse[x], fd2);
		}
		exit(0);
	}
}

void first_argis_symbol(char **parse)
{
	char *str;
	int x;
	int ctrl;

	x = -1;
	while (parse[++x] && parse[x + 1] != 0)
	{
		str = parse[x + 1];
		parse[x + 1] = ft_strtrim(str, " ");
		free(str);
		if (ft_strcmp(parse[x], ">") == 0)
			rdr_actuator(parse[x + 1], 1);
		else if (ft_strcmp(parse[x], "<") == 0)
			ctrl = rdr_actuator(parse[x + 1], 2);
		else if (ft_strncmp(parse[x], ">>", 2) == 0)
			rdr_actuator(parse[x + 1], 3);
		else if (ft_strncmp(parse[x], "<<", 2) == 0)
			rdr_actuator(parse[x + 1], 4);
	}
	if (ctrl != 0)
		rdr_runner_for_first_arg(parse, x);
}
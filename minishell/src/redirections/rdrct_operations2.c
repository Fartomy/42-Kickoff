/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:41:11 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rdr_input(int ctrl)
{
	if (ctrl == 0)
	{
		dup2(g_dt.fd, 0);
		close(g_dt.fd);
	}
	else if (ctrl == 1)
	{
		dup2(g_dt.fd2, 0);
		close(g_dt.fd2);
	}
}

void	heredoc_oprt(char *prs, int *fd2)
{
	int	pid2;

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
		heredoc_oprt_helper(prs, fd2);
		exit(0);
	}
}

static void	rdr_rnr_output(char **parse)
{
	int	fd2[2];

	if (ft_strncmp(parse[0], "<<", 2) == 0)
		heredoc_oprt(parse[1], fd2);
	else if (ft_strcmp(parse[0], "<") == 0)
		rdr_input(1);
	dup2(g_dt.fd, 1);
	close(g_dt.fd);
}

static void	rdr_runner_for_first_arg(char **parse, int x)
{
	int	pid;
	int	fd2[2];

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (ft_strcmp(parse[x - 1], ">") == 0)
			rdr_rnr_output(parse);
		else if (ft_strcmp(parse[x - 1], "<") == 0)
		{
			dup2(g_dt.fd, 0);
			close(g_dt.fd);
		}
		else if (ft_strncmp(parse[x - 1], ">>", 2) == 0)
			rdr_rnr_output(parse);
		else if (ft_strncmp(parse[x - 1], "<<", 2) == 0)
			heredoc_oprt(parse[x], fd2);
		exit(0);
	}
}

void	first_argis_symbol(char **parse)
{
	char	*str;
	int		x;
	int		ctrl;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:41:11 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/31 17:29:13 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			dup2(data.fd, 1);
			close(data.fd);
		}
		else if (ft_strncmp(parse[x - 1], "<<", 2) == 0)
			heredoc_oprt(parse, x);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:08:33 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/01 18:14:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void rdr_runner(char **parse, int x)
{
	int pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (ft_strcmp(parse[x - 1], ">") == 0)
		{
			if(ft_strncmp(parse[1], "<<", 2) == 0)
			{
				int fd2[2];
				heredoc_oprt(parse[2], fd2);
			}
			else if(ft_strcmp(parse[1], "<") == 0)
				rdr_input(1);
			dup2(data.fd, 1);
			close(data.fd);
		}
		else if (ft_strcmp(parse[x - 1], "<") == 0)
			rdr_input(0);
		else if (ft_strncmp(parse[x - 1], ">>", 2) == 0)
		{
			if(ft_strncmp(parse[1], "<<", 2) == 0)
			{
				int fd2[2];
				heredoc_oprt(parse[2], fd2);
			}
			else if(ft_strcmp(parse[1], "<") == 0)
				rdr_input(1);
			dup2(data.fd, 1);
			close(data.fd);
		}
		else if (ft_strncmp(parse[x - 1], "<<", 2) == 0)
		{
			int fd2[2];
			heredoc_oprt(parse[x], fd2);
		}
		builtin_or_smp_cmd_ctrl(parse);
		exit(0);
	}
}

int rdr_actuator(char *prs, int ctrl)
{
	data.fd = 0;
	if (ctrl == 1)
		data.fd = open(prs, O_RDWR | O_CREAT, 0777);
	else if (ctrl == 2)
	{
		data.fd = open(prs, O_RDWR);
		data.fd2 = dup(data.fd);
		if (data.fd == -1)
		{
			printf("minishell: %s: No such file or directory\n", prs);
			return (0);
		}
	}
	else if (ctrl == 3)
		data.fd = open(prs, O_RDWR | O_CREAT | O_APPEND, 0777);
	return (1);
}

void rdr_stream(char **parse)
{
	int x;
	char *str;
	int ctrl;

	x = 0;
	while (data.symbol_tkn[x])
	{
		if (ft_strncmp(parse[0], data.symbol_tkn[x], ft_strlen(data.symbol_tkn[x])) == 0)
		{
			first_argis_symbol(parse);
			return ;
		}
		x++;
	}
	x = 0;
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
	}
	if (ctrl != 0)
		rdr_runner(parse, x);
}

void ft_redirecton(char **parse)
{
	if (!redirct_err_ctrl_for_output(parse))
		return;
	if (!redirct_err_ctrl_for_input(parse))
		return;
	if (!redirct_err_ctrl_for_append(parse))
		return;
	if (!redirct_err_ctrl_for_heredoc(parse))
		return;
	if (!redirct_err_ctrl(parse))
		return;
	rdr_stream(parse);
}
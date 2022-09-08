/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:08:33 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rdr_runner(char **parse, int x)
{
	int	pid;
	int	fd2[2];

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (ft_strcmp(parse[x - 1], ">") == 0)
			rdr_runner_helper(parse, fd2);
		else if (ft_strcmp(parse[x - 1], "<") == 0)
			rdr_input(0);
		else if (ft_strncmp(parse[x - 1], ">>", 2) == 0)
			rdr_runner_helper(parse, fd2);
		else if (ft_strncmp(parse[x - 1], "<<", 2) == 0)
			heredoc_oprt(parse[x], fd2);
		builtin_or_smp_cmd_ctrl(&parse[0]);
		exit(0);
	}
}

int	rdr_actuator(char *prs, int ctrl)
{
	g_dt.fd = 0;
	if (ctrl == 1)
		g_dt.fd = open(prs, O_RDWR | O_CREAT, 0777);
	else if (ctrl == 2)
	{
		g_dt.fd = open(prs, O_RDWR);
		g_dt.fd2 = dup(g_dt.fd);
		if (g_dt.fd == -1)
		{
			printf("minishell: %s: No such file or directory\n", prs);
			g_dt.status = 1;
			return (0);
		}
	}
	else if (ctrl == 3)
		g_dt.fd = open(prs, O_RDWR | O_CREAT | O_APPEND, 0777);
	return (1);
}

void	rdr_stream(char **parse)
{
	int		x;
	int		ctrl;

	x = 0;
	while (g_dt.symbol_tkn[x])
	{
		if (ft_strncmp(parse[0], g_dt.symbol_tkn[x], \
			ft_strlen(g_dt.symbol_tkn[x])) == 0)
		{
			first_argis_symbol(parse);
			return ;
		}
		x++;
	}
	x = 0;
	while (parse[++x] && parse[x + 1] != 0)
	{
		parse[x + 1] = rdr_stream_mini_helper(parse, x);
		if (!rdr_stream_helper(parse, &ctrl, x))
			break ;
	}
	if (ctrl != 0)
		rdr_runner(parse, x);
}

void	ft_redirecton(char **parse)
{
	if (!redirct_err_ctrl_for_output(parse))
		return ;
	if (!redirct_err_ctrl_for_input(parse))
		return ;
	if (!redirct_err_ctrl_for_append(parse))
		return ;
	if (!redirct_err_ctrl_for_heredoc(parse))
		return ;
	if (!redirct_err_ctrl(parse))
		return ;
	rdr_stream(parse);
}

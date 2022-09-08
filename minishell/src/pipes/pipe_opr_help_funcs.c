/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_opr_help_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:15:28 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:44:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd_body(int **pfd, char **parse, int *p, int i)
{
	if (*p == 0)
		pipe_cmd_first_arg(pfd, p);
	else if (*p + 1 != i)
		pipe_cmd_betw_arg(pfd, p);
	else if (*p + 1 == i)
		pipe_cmd_last_arg(pfd, p);
	simple_cmd(parse);
	exit(0);
}

void	pipe_cmd_first_arg(int **pfd, int *p)
{
	dup2(pfd[*p + 1][1], 1);
	close(pfd[*p][1]);
	close(pfd[*p][0]);
}

void	pipe_cmd_betw_arg(int **pfd, int *p)
{
	dup2(pfd[*p][0], 0);
	dup2(pfd[*p + 1][1], 1);
	close(pfd[*p][1]);
	close(pfd[*p][0]);
}

void	pipe_cmd_last_arg(int **pfd, int *p)
{
	dup2(pfd[*p][0], 0);
	close(pfd[*p][1]);
	close(pfd[*p][0]);
}

void	pipe_cmd_close(int **pfd, int p)
{
	close(pfd[p][1]);
	close(pfd[p][0]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:52:06 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 17:20:17 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_cnt(char **s)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (ft_strcmp(s[i], "|") == 0)
			cnt++;
	}
	return (cnt);
}

void	pipe_cmd_storage(int ***pfd, int **pids, int i, int *p)
{
	int	x;

	x = -1;
	*pfd = ft_calloc(sizeof(int **), i);
	*pids = ft_calloc(sizeof(int), i);
	while (++x < i)
	{
		(*pfd)[x] = ft_calloc(sizeof(int), 2);
		pipe((*pfd)[x]);
	}
	x = -1;
	*p = -1;
}

void	pipe_cmd_free(int i, int *pids, int **pfd)
{
	int	x;

	x = -1;
	while (i > ++x)
		free(pfd[x]);
	free(pfd);
	free(pids);
}

void	pipe_cmd_wait(int i)
{
	int	p;

	p = -1;
	while (++p < i)
		wait(NULL);
}

void	piped_command(char **parse)
{
	int	i;
	int	p;
	int	x;
	int	**pfd;
	int	*pids;

	pfd = NULL;
	pids = NULL;
	i = pipe_err_ctrl(parse);
	if (i == 0)
		return ;
	x = -1;
	i = pipe_cnt(parse) + 1;
	pipe_cmd_storage(&pfd, &pids, i, &p);
	while (++p <= i && parse[++x] != 0)
	{
		if (ft_strcmp(parse[x], "|") == 0)
			x++;
		pids[p] = fork();
		if (pids[p] == 0)
			pipe_cmd_body(pfd, &parse[x], &p, i);
		pipe_cmd_close(pfd, p);
	}
	pipe_cmd_wait(i);
	pipe_cmd_free(i, pids, pfd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:52:06 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 15:22:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int pipe_cnt(char **s)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (ft_strcmp(s[i], "|") == 0)
			cnt++;
	}
	return (cnt);
}

void	piped_command(char **parse)
{
	int ctrl;
	int i;
	int p;
	int x;
	int **pfd;
	int *pids;

	ctrl = pipe_err_ctrl(parse);
	if (ctrl == 0)
		return;
	i = pipe_cnt(parse) + 1;
	pfd = malloc(sizeof(int *) * i);
	x = -1;
	while (++x < i)
		pfd[x] = malloc(sizeof(int) * 2);
	x = -1;
	while (++x < i)
		pipe(pfd[x]);
	pids = ft_calloc(i, sizeof(int));
	x = -1;
	p = -1;
	while (++p <= i && parse[++x] != 0)
	{
		if (ft_strcmp(parse[x], "|") == 0)
			x++;
		pids[p] = fork();
		if (pids[p] == 0)
		{
			if (p == 0)
			{
				dup2(pfd[p + 1][1], 1);
				close(pfd[p][1]);
				close(pfd[p][0]);
			}
			else if (p + 1 != i)
			{
				dup2(pfd[p][0], 0);
				dup2(pfd[p + 1][1], 1);
				close(pfd[p][1]);
				close(pfd[p][0]);
			}
			else if (p + 1 == i)
			{
				dup2(pfd[p][0], 0);
				close(pfd[p][1]);
				close(pfd[p][0]);
			}
			simple_cmd(&parse[x]);
			exit(0);
		}
		close(pfd[p][1]);
		close(pfd[p][0]);
	}
	p = -1;
	while(++p < i)
		wait(NULL);
	int a;
	a = -1;
	while (i > ++a)
		free(pfd[a]);
	free(pfd);
	free(pids);
}
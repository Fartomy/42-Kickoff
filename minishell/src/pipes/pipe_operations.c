/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:52:06 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/05 23:01:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_cmd_finishing(t_pipe_command_vars *pcm)
{
	pcm->p = -1;
	while (++pcm->p < pcm->i)
		wait(NULL);
	pcm->a = -1;
	while (pcm->i > ++pcm->a)
		free(pcm->pfd[pcm->a]);
	free(pcm->pfd);
	free(pcm->pids);
}

static void	pipe_cmd_storage(t_pipe_command_vars *pcm)
{
	pcm->pfd = ft_calloc(sizeof(int *), pcm->i);
	pcm->pids = ft_calloc(pcm->i, sizeof(int));
	pcm->x = -1;
	while (++pcm->x < pcm->i)
	{
		pcm->pfd[pcm->x] = ft_calloc(sizeof(int), 2);
		pipe(pcm->pfd[pcm->x]);
	}
	pcm->x = -1;
	pcm->p = -1;
}

static void	pipe_cmd_pipe_body(t_pipe_command_vars *pcm)
{
	if (pcm->p == 0)
		pipe_cmd_first_command(pcm);
	else if (pcm->p + 1 != pcm->i)
		pipe_cmd_betw_command(pcm);
	else if (pcm->p + 1 == pcm->i)
		pipe_cmd_last_command(pcm);
}

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

void	piped_command(char **parse)
{
	t_pipe_command_vars	pcmd;

	pcmd.ctrl = pipe_err_ctrl(parse);
	if (pcmd.ctrl == 0)
		return ;
	pcmd.i = pipe_cnt(parse) + 1;
	pipe_cmd_storage(&pcmd);
	while (++pcmd.p <= pcmd.i && parse[++pcmd.x] != 0)
	{
		if (ft_strcmp(parse[pcmd.x], "|") == 0)
			pcmd.x++;
		pcmd.pids[pcmd.p] = fork();
		if (pcmd.pids[pcmd.p] == 0)
		{
			pipe_cmd_pipe_body(&pcmd);
			simple_cmd(&parse[pcmd.x]);
			exit(0);
		}
		close(pcmd.pfd[pcmd.p][1]);
		close(pcmd.pfd[pcmd.p][0]);
	}
	pipe_cmd_finishing(&pcmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_opr_help_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:01:17 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/05 23:02:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd_last_command(t_pipe_command_vars *pcm)
{
	dup2(pcm->pfd[pcm->p][0], 0);
	close(pcm->pfd[pcm->p][1]);
	close(pcm->pfd[pcm->p][0]);
}

void	pipe_cmd_betw_command(t_pipe_command_vars *pcm)
{
	dup2(pcm->pfd[pcm->p][0], 0);
	dup2(pcm->pfd[pcm->p + 1][1], 1);
	close(pcm->pfd[pcm->p][1]);
	close(pcm->pfd[pcm->p][0]);
}

void	pipe_cmd_first_command(t_pipe_command_vars *pcm)
{
	dup2(pcm->pfd[pcm->p + 1][1], 1);
	close(pcm->pfd[pcm->p][1]);
	close(pcm->pfd[pcm->p][0]);
}

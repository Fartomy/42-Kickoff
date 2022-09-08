/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_oprt_help_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:23:33 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rdr_runner_helper(char **parse, int *fd2)
{
	if (ft_strncmp(parse[1], "<<", 2) == 0)
		heredoc_oprt(parse[2], fd2);
	else if (ft_strcmp(parse[1], "<") == 0)
		rdr_input(1);
	dup2(g_dt.fd, 1);
	close(g_dt.fd);
}

int	rdr_stream_helper(char **parse, int *ctrl, int x)
{
	if (ft_strcmp(parse[x], ">") == 0)
		rdr_actuator(parse[x + 1], 1);
	else if (ft_strcmp(parse[x], "<") == 0)
	{
		*ctrl = rdr_actuator(parse[x + 1], 2);
		if (*ctrl == 0)
			return (0);
	}
	else if (ft_strncmp(parse[x], ">>", 2) == 0)
		rdr_actuator(parse[x + 1], 3);
	return (1);
}

char	*rdr_stream_mini_helper(char **parse, int x)
{
	char	*str;

	str = parse[x + 1];
	parse[x + 1] = ft_strtrim(str, " ");
	free(str);
	return (parse[x + 1]);
}

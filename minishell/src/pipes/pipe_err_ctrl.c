/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:41:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_err_msg(void)
{
	printf("minishell: syntax error near unexpected token `|'\n");
	g_dt.status = 258;
	return (1);
}

int	pipe_err_ctrl(char **parse)
{
	int	i;

	i = 0;
	if (ft_strcmp(parse[0], "|") == 0)
		if (pipe_err_msg())
			return (0);
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "|") == 0 && parse[i + 1] == 0)
			if (pipe_err_msg())
				return (0);
		if (!ft_strcmp(parse[i], "|") && !ft_strcmp(parse[i + 1], " ") \
			&& !parse[i + 2])
			if (pipe_err_msg())
				return (0);
		if (!ft_strcmp(parse[i], "|") && !ft_strcmp(parse[i + 1], " ") \
			&& !ft_strcmp(parse[i + 2], "|"))
			if (pipe_err_msg())
				return (0);
		i++;
	}
	return (1);
}

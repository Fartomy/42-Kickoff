/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:41:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/02 12:22:43 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pipe_err_ctrl(char **parse)
{
	int i;

	i = -1;
	if(ft_strcmp(parse[0], "|") == 0)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	while (parse[++i])
	{
		if(ft_strcmp(parse[i], parse[i + 1]) == 0)
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			return (0);
		}
	}
	i = ft_arglen(parse);
	printf("%s\n", parse[i - 1]);
	return (1);
}
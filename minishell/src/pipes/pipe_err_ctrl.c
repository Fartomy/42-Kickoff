/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:41:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 16:59:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pipe_err_ctrl(char **parse)
{
	int i;

	i = 0;
	if(ft_strcmp(parse[0], "|") == 0)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		data.status = 258;
		return (0);
	}
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "|") == 0 && parse[i + 1] == 0)
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			data.status = 258;
			return (0);
		}
		else if(ft_strcmp(parse[i], "|") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && parse[i + 2] == 0)
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			data.status = 258;
			return (0);	
		}
		else if(ft_strcmp(parse[i], "|") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && ft_strcmp(parse[i + 2], "|") == 0)
		{
			printf("minishell: syntax error near unexpected token `|'\n");
			data.status = 258;
			return (0);
		}
		i++;
	}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:17:52 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 13:57:38 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arglen(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

int	cmd_space_ctrl(char *cmd)
{
	while (*cmd)
	{
		if (*cmd != ' ')
			return (0);
		cmd++;
	}
	return (1);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	set_builtin_token(char **bl_token)
{
	bl_token[0] = "echo";
	bl_token[1] = "cd";
	bl_token[2] = "pwd";
	bl_token[3] = "export";
	bl_token[4] = "unset";
	bl_token[5] = "env";
	bl_token[6] = "exit";
	bl_token[7] = 0;
}

void	set_symbol_token(char **sy_token)
{
	sy_token[0] = "<";
	sy_token[1] = ">";
	sy_token[2] = "<<";
	sy_token[3] = ">>";
	sy_token[4] = NULL;
}

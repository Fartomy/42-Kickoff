/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:15:48 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:57:36 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	equal_finder(char *var)
{
	int	i;

	i = -1;
	while (var[++i])
	{
		if (var[i] == '=')
			return (1);
	}
	return (0);
}

char	*env_name_getter(char *var)
{
	int		i;
	char	*name;

	i = 0;
	while (var[i] != '=' && var[i])
		i++;
	name = ft_calloc(sizeof(char), (i + 1));
	i = -1;
	while (var[++i] != '=' && var[i])
		name[i] = var[i];
	name[i] = 0;
	return (name);
}

char	**export_sorter(char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		if (envp[i + 1] && (envp[i][0] > envp[i + 1][0]))
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (envp);
}

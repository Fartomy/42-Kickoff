/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:08:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 14:00:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_env(char **parse, char **name, int i)
{
	int		x;
	char	*tmp;

	x = -1;
	while (data.env[++x])
	{
		*name = env_name_getter(data.env[x]);
		if (ft_strcmp(*name, parse[i]) == 0)
		{
			free(*name);
			while (data.env[x] && data.env[x + 1])
			{
				tmp = data.env[x + 1];
				data.env[x + 1] = data.env[x];
				data.env[x++] = tmp;
			}
			if (data.env[x + 1] == 0)
			{
				if (unset_env_helper(x))
					break ;
			}
		}
		if (*name)
			free(*name);
	}
}

static void	unset_export(char **parse, char **name, int i)
{
	int		x;
	char	*tmp;

	x = -1;
	while (data.export[++x])
	{
		*name = env_name_getter(data.export[x]);
		if (ft_strcmp(*name, parse[i]) == 0)
		{
			free(*name);
			while (data.export[x] && data.export[x + 1])
			{
				tmp = data.export[x + 1];
				data.export[x + 1] = data.export[x];
				data.export[x++] = tmp;
			}
			if (data.export[x + 1] == 0)
				if (unset_export_helper(x))
					break ;
		}
		if (*name)
			free(*name);
	}
}

void	ft_unset(char **parse)
{
	int		i;
	char	*name;

	i = 0;
	if (!parse[++i])
	{
		printf("");
		data.status = 0;
		return ;
	}
	while (parse[i])
	{
		if (equal_finder(parse[i]) == 0)
		{
			unset_env(parse, &name, i);
			unset_export(parse, &name, i);
		}
		else
			unset_error(parse, i);
		i++;
	}
	data.status = 0;
}

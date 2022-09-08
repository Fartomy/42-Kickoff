/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:08:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_env(char **parse, char **name, int i)
{
	int		x;
	char	*tmp;

	x = -1;
	while (g_dt.env[++x])
	{
		*name = env_name_getter(g_dt.env[x]);
		if (ft_strcmp(*name, parse[i]) == 0)
		{
			free(*name);
			while (g_dt.env[x] && g_dt.env[x + 1])
			{
				tmp = g_dt.env[x + 1];
				g_dt.env[x + 1] = g_dt.env[x];
				g_dt.env[x++] = tmp;
			}
			if (g_dt.env[x + 1] == 0)
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
	while (g_dt.export[++x])
	{
		*name = env_name_getter(g_dt.export[x]);
		if (ft_strcmp(*name, parse[i]) == 0)
		{
			free(*name);
			while (g_dt.export[x] && g_dt.export[x + 1])
			{
				tmp = g_dt.export[x + 1];
				g_dt.export[x + 1] = g_dt.export[x];
				g_dt.export[x++] = tmp;
			}
			if (g_dt.export[x + 1] == 0)
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
		g_dt.status = 0;
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
	g_dt.status = 0;
}

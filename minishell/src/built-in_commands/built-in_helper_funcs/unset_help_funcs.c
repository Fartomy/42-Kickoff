/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_help_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:59:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env_helper(int x)
{
	free(g_dt.env[x]);
	g_dt.env[x] = 0;
	g_dt.env = ft_rrealloc(g_dt.env, ft_arglen(g_dt.env));
	return (1);
}

int	unset_export_helper(int x)
{
	free(g_dt.export[x]);
	g_dt.export[x] = 0;
	g_dt.export = ft_rrealloc(g_dt.export, \
					ft_arglen(g_dt.export));
	return (1);
}

void	unset_error(char **parse, int i)
{
	g_dt.status = 1;
	printf("minishell: unset: `%s': not a valid identifier\n", parse[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_help_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:59:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 14:01:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env_helper(int x)
{
	free(data.env[x]);
	data.env[x] = 0;
	data.env = ft_rrealloc(data.env, ft_arglen(data.env));
	return (1);
}

int	unset_export_helper(int x)
{
	free(data.export[x]);
	data.export[x] = 0;
	data.export = ft_rrealloc(data.export, \
					ft_arglen(data.export));
	return (1);
}

void	unset_error(char **parse, int i)
{
	data.status = 1;
	printf("minishell: unset: `%s': not a valid identifier\n", parse[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:21:08 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **parse)
{
	int	i;

	i = 0;
	if (ft_strcmp(parse[i], "env") == 0 && !parse[i + 1])
	{
		while (g_dt.env[i])
			printf("%s\n", g_dt.env[i++]);
		g_dt.status = 0;
	}
	else if (ft_strcmp(parse[i], "env") == 0 && parse[i + 1])
	{
		g_dt.status = 127;
		printf("%s: %s: No such file or directory\n", parse[i], parse[i + 1]);
	}
}

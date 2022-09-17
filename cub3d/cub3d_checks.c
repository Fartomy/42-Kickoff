/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:32:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/18 02:32:42 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_format_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (*av == 0 || i-- < 5)
		return (0);
	if (av[i] == 'b' && av[i - 1] == 'u' && \
		av[i - 2] == 'c' && \
		av[i - 3] == '.')
		return (1);
	else
		return (0);
}

static int	identifer_ctrl(char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '\t')
			i++;
		else if(ft_isalpha(str[i]))
		{
			if(str[i] != ' ' && str[i])
		}
			//
		else
			return(0);
	}
	return (0);
}

int map_features_check(t_data *data)
{
	int i;

	i = 0;
	while (i < 6)
	{
		
	}
	
}
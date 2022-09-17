/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:32:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/18 00:22:18 by ftekdrmi         ###   ########.fr       */
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

/*int map_features_check(t_data *data)
{
	
}*/
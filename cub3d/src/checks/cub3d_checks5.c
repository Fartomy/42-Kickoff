/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:42:42 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/22 15:10:33 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_check(t_data *data, int i)
{
	int a;
	int y;

	y = 0;
	a = i;
	if(data->map_and_ftrs[a] != 0)
	{
		while (data->map_and_ftrs[a++])
			y++;
		data->map = ft_calloc(y, sizeof(char *) + 1);
		y = 0;
		while (data->map_and_ftrs[i])
		{
			data->map[y] = ft_calloc(ft_strlen(data->map_and_ftrs[i]), sizeof(char) + 1);
			ft_strcpy(data->map[y++], data->map_and_ftrs[i++]);
		}
		data->map[y] = 0;
	}
	else
	{
		write(2, "Error\nMap Not Found!", 20);
		//free?
		exit(1);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:05:16 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/22 19:59:07 by ftekdrmi         ###   ########.fr       */
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
		ft_arg_free(data->map_and_ftrs);
	}
	else
	{
		write(2, "Error\nMap Not Found!", 20);
		exit(1);
	}
}

void	map_all_check(t_data *data)
{
	int	arg;
	int	idx;

	arg = 0;
	idx = 0;
	while (arg < ft_arglen(data->map))
	{
		idx = 0;
		while (data->map[arg][idx])
		{
			if (data->map[arg][idx] == '0' || data->map[arg][idx] == 'N' || \
				data->map[arg][idx] == '1' || data->map[arg][idx] == 'S' || \
				data->map[arg][idx] == 'E' || data->map[arg][idx] == 'W')
					idx++;
			else
			{
				write(1, "Error\nUndefined Character!\n", 28);
				printf("Arg: %d\nIdx: %d\n", arg, idx);
				exit(1);
			}
		}
		arg++;
	}
}
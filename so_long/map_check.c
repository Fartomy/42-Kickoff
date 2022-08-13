/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:40:19 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 20:45:30 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (*av == 0 || i-- < 5)
		return (0);
	if (av[i] == 'r' && av[i - 1] == 'e' && \
		av[i - 2] == 'b' && \
		av[i - 3] == '.')
		return (1);
	else
		return (0);
}

void	map_ltr_check(t_data *data)
{
	while (data->map[data->ltr_check.ltr_arg])
	{
		data->ltr_check.ltr_idx = 0;
		while (data->map[data->ltr_check.ltr_arg][data->ltr_check.ltr_idx])
		{
			if (data->map[data->ltr_check.ltr_arg] \
				[data->ltr_check.ltr_idx] == 'P')
			data->ltr_check.p_cnt++;
			else if (data->map[data->ltr_check.ltr_arg] \
					[data->ltr_check.ltr_idx] == 'E')
			data->ltr_check.e_cnt++;
			else if (data->map[data->ltr_check.ltr_arg] \
					[data->ltr_check.ltr_idx] == 'C')
			data->ltr_check.c_cnt++;
			data->ltr_check.ltr_idx++;
		}
		data->ltr_check.ltr_arg++;
	}
	if (data->ltr_check.p_cnt == 0 || data->ltr_check.p_cnt > 1 || \
		data->ltr_check.e_cnt == 0 || data->ltr_check.c_cnt == 0)
	{
		write(1, "Error\nPlayer or Collectable or Exit is Wrong!", 46);
		exit(1);
	}
}

static void	left_vertical_check(t_data *data)
{
	while (data->map[data->ltr_check.wall_chk_arg])
	{
		if (data->map[data->ltr_check.wall_chk_arg][0] != '1')
		{
			write(1, "Error\nLeft Vertical Wall is Wrong!", 36);
			exit(1);
		}
		data->ltr_check.wall_chk_arg++;
	}
}

static void	top_horizontal_check(t_data *data)
{
	while (data->map[0][data->ltr_check.wal_chk_idx])
	{
		if (data->map[0][data->ltr_check.wal_chk_idx] != '1')
		{
			write(1, "Error\nTop Horizantal Wall is Wrong!", 36);
			exit(1);
		}
		data->ltr_check.wal_chk_idx++;
	}
}

/*
1rd Loop: Bottom Horizontal Wall
2st Loop: Right Vertical Wall

(For bottom function!)
*/

void	map_wall_check(t_data *data)
{
	left_vertical_check(data);
	top_horizontal_check(data);
	data->ltr_check.wall_chk_arg -= 1;
	data->ltr_check.wal_chk_idx = 0;
	while (data->map[data->ltr_check.wall_chk_arg][data->ltr_check.wal_chk_idx])
	{
		if (data->map[data->ltr_check.wall_chk_arg] \
			[data->ltr_check.wal_chk_idx] != '1')
		{
			write(1, "Error\nBottom Horizontal Wall is Wrong!", 39);
			exit(1);
		}
		data->ltr_check.wal_chk_idx++;
	}
	data->ltr_check.wal_chk_idx -= 1;
	while (data->ltr_check.wall_chk_arg > 0)
	{
		if (data->map[data->ltr_check.wall_chk_arg] \
			[data->ltr_check.wal_chk_idx] != '1')
		{
			write(1, "Error\nRight Vertical Wall is Wrong!", 36);
			exit(1);
		}
		data->ltr_check.wall_chk_arg--;
	}
}

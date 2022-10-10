/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:22:42 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/09 16:00:46 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/cub3d.h"

static void	bottom_horizontal_check(t_data2 *data)
{
	data->wal_chk_arg -= 1;
	data->wal_chk_idx = 0;
	while (data->map[data->wal_chk_arg][data->wal_chk_idx])
	{
		if (data->map[data->wal_chk_arg] \
			[data->wal_chk_idx] != '1')
		{
			write(1, "Error\nBottom Horizontal Wall is Wrong!", 38);
			exit(1);
		}
		data->wal_chk_idx++;
	}
}

static void	left_vertical_check(t_data2 *data)
{
	while (data->map[data->wal_chk_arg])
	{
		if (data->map[data->wal_chk_arg][0] != '1')
		{
			write(1, "Error\nLeft Vertical Wall is Wrong!", 34);
			exit(1);
		}
		data->wal_chk_arg++;
	}
}

static void	top_horizontal_check(t_data2 *data)
{
	while (data->map[0][data->wal_chk_idx])
	{
		if (data->map[0][data->wal_chk_idx] != '1')
		{
			write(1, "Error\nTop Horizantal Wall is Wrong!", 35);
			exit(1);
		}
		data->wal_chk_idx++;
	}
}

void	map_wall_check(t_data2 *data)
{
	left_vertical_check(data);
	top_horizontal_check(data);
	bottom_horizontal_check(data);
	right_vertical_check(data);
}

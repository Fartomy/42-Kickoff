/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:22:42 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/28 00:09:50 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	bottom_horizontal_check(t_data *data)
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

static void	left_vertical_check(t_data *data)
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

static void	top_horizontal_check(t_data *data)
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

static void	is_wall_open(int i, char *big_line)
{
	while (big_line[i])
	{
		if(big_line[i] == '0')
		{
			write(2, "Error\nRight Vertical Wall is Wrong!", 35);
			exit(1);
		}
		i++;
	}
}

static void	right_vertical_check(t_data *data)
{
	int size_sml;
	
	data->wal_chk_arg = -1;
	while (data->map[++data->wal_chk_arg] && data->map[data->wal_chk_arg + 1])
	{
		if(ft_strlen(data->map[data->wal_chk_arg]) > ft_strlen(data->map[data->wal_chk_arg + 1]))
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg + 1]);
			is_wall_open(size_sml, data->map[data->wal_chk_arg]);
		}
		else if(ft_strlen(data->map[data->wal_chk_arg]) < ft_strlen(data->map[data->wal_chk_arg + 1]))
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg]);
			is_wall_open(size_sml, data->map[data->wal_chk_arg + 1]);
		}
		else
		{
			if((data->map[data->wal_chk_arg][data->wal_chk_arg] != 1 || data->map[data->wal_chk_arg + 1][data->wal_chk_arg] != 1))
			{
				write(2, "Error\nRight Vertical Wall is Wrong!", 35);
				exit(1);
			}
		}
	}
}

void	map_wall_check(t_data *data)
{
	left_vertical_check(data);
	top_horizontal_check(data);
	bottom_horizontal_check(data);
	right_vertical_check(data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:46:13 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 17:15:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_rectangle_check(t_data *data)
{
	int	arg;

	arg = 1;
	while (data->map[arg])
	{
		if (row_cnt(data->map[0]) != row_cnt(data->map[arg]))
		{
			write(1, "Error\nMap is not Rectangle!", 28);
			exit(1);
		}
		arg++;
	}
}

void	map_newline_check(t_data *data)
{
	if (data->row_cnt != data->nw_cnt)
	{
		write(1, "Error\nMap is Broke!", 20);
		exit(1);
	}
}

void	map_all_check(t_data *data)
{
	int	arg;
	int	idx;

	arg = 1;
	idx = 1;
	while (arg < data->row_cnt)
	{
		idx = 1;
		while (data->map[arg][idx])
		{
			if (data->map[arg][idx] == '0' || data->map[arg][idx] == 'P' || \
				data->map[arg][idx] == '1' || data->map[arg][idx] == 'C' || \
				data->map[arg][idx] == 'E')
					idx++;
			else
			{
				write(1, "Error\nUndefined Character!\n", 28);
				ft_printf("Arg: %d\nIdx: %d\n", arg, idx);
				exit(1);
			}
		}
		arg++;
	}
}

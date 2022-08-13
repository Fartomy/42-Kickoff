/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 01:00:28 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 20:05:45 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_create(t_data *data)
{
	int	x;
	int	y;

	data->img_path = ft_calloc(8, sizeof(void *));
	if (!data->img_path)
	{
		free(data->img_path);
		exit(0);
	}
	data->img_path[0] = mlx_xpm_file_to_image(data->mlx, "./xpm/W.xpm", &x, &y);
	data->img_path[1] = mlx_xpm_file_to_image(data->mlx, "./xpm/F.xpm", &x, &y);
	data->img_path[2] = mlx_xpm_file_to_image(data->mlx, "./xpm/R.xpm", &x, &y);
	data->img_path[3] = mlx_xpm_file_to_image(data->mlx, "./xpm/L.xpm", &x, &y);
	data->img_path[4] = mlx_xpm_file_to_image(data->mlx, "./xpm/B.xpm", &x, &y);
	data->img_path[5] = mlx_xpm_file_to_image(data->mlx, "./xpm/S.xpm", &x, &y);
	data->img_path[6] = mlx_xpm_file_to_image(data->mlx, "./xpm/E.xpm", &x, &y);
	data->img_path[7] = mlx_xpm_file_to_image(data->mlx, "./xpm/D.xpm", &x, &y);
}

static void	map_put_img_for_zero(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, \
	data->img_path[7], data->img_idx * 64, data->img_arg * 64);
}

static void	map_put_img_for_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, \
	data->img_path[1], data->img_idx * 64, data->img_arg * 64);
	data->xp = data->img_idx;
	data->yp = data->img_arg;
}

void	map_put_image(t_data *data)
{
	while (data->map[data->img_arg])
	{
		data->img_idx = 0;
		while (data->map[data->img_arg][data->img_idx])
		{
			if (data->map[data->img_arg][data->img_idx] == '0')
				map_put_img_for_zero(data);
			else if (data->map[data->img_arg][data->img_idx] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
				data->img_path[0], data->img_idx * 64, data->img_arg * 64);
			else if (data->map[data->img_arg][data->img_idx] == 'P')
				map_put_img_for_player(data);
			else if (data->map[data->img_arg][data->img_idx] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, \
				data->img_path[5], data->img_idx * 64, data->img_arg * 64);
				data->ttl_clc++;
			}
			else if (data->map[data->img_arg][data->img_idx] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, \
				data->img_path[6], data->img_idx * 64, data->img_arg * 64);
			data->img_idx++;
		}
		data->img_arg++;
	}
}

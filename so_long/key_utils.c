/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:06:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 13:42:09 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_data *data)
{
	if (data->map[data->yp - 1][data->xp] != '1' && \
		(data->map[data->yp - 1][data->xp] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[7], data->xp * 64, data->yp * 64);
		data->yp -= 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[4], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
			ft_printf("\aSCORE: %d\n", data->score);
		}
		ft_printf("Adım Sayısı: %d\n", data->step_cnt++);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Toplanan Sarma: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_s(t_data *data)
{
	if (data->map[data->yp + 1][data->xp] != '1' && \
		(data->map[data->yp + 1][data->xp] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[7], data->xp * 64, data->yp * 64);
		data->yp += 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[1], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
			ft_printf("\aSCORE: %d\n", data->score);
		}
		ft_printf("Adım Sayısı: %d\n", data->step_cnt++);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Toplanan Sarma: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_a(t_data *data)
{
	if (data->map[data->yp][data->xp - 1] != '1' && \
		(data->map[data->yp][data->xp - 1] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[7], data->xp * 64, data->yp * 64);
		data->xp -= 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[2], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
			ft_printf("\aSCORE: %d\n", data->score);
		}
		ft_printf("Adım Sayısı: %d\n", data->step_cnt++);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Toplanan Sarma: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_d(t_data *data)
{
	if (data->map[data->yp][data->xp + 1] != '1' && \
		(data->map[data->yp][data->xp + 1] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[7], data->xp * 64, data->yp * 64);
		data->xp += 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[3], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
			ft_printf("\aSCORE: %d\n", data->score);
		}
		ft_printf("Adım Sayısı: %d\n", data->step_cnt++);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Toplanan Sarma: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_esc(t_data *data)
{
	clean_up(data);
}

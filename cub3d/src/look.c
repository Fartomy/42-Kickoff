/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:43 by syildiri          #+#    #+#             */
/*   Updated: 2022/10/10 11:02:42 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cube.h"

int	int_abs(int i)
{
	return (i * ((i > 0) * 2 - 1));
}

float	float_abs(float i)
{
	return (i * ((i > 0) * 2 - 1));
}

float	get_distance(t_vector2f a, t_vector2f b)
{
	float	x;
	float	y;

	if (float_approximately(a.x, b.x))
		return (float_abs(a.y - b.y));
	if (float_approximately(a.y, b.y))
		return (float_abs(a.x - b.x));
	x = a.x - b.x;
	y = a.y - b.y;
	return (sqrt(x * x + y * y));
}

t_found	look_horizontal(t_data *data, float f_slope, int add)
{
	float	f_add;
	int		i;
	float	y;

	i = data->pos.x;
	i += add;
	f_add = data->pos.y - (f_slope * data->pos.x);
	while (1)
	{
		y = f_slope * (i + (add < 0)) + f_add;
		if (y < 0 || (int)y >= data->y_size || i < 0 || i >= data->x_size)
			return ((t_found){0x7FFFFFFF, 0});
		if (data->map[(int)y][i] == '1')
		{
			return ((t_found){get_distance((t_vector2f){i + (add < 0), y},
				data->pos), y - (int)y});
		}
		i += add;
	}
}

t_found	look_vertical(t_data *data, float f_slope, int add)
{
	float	f_add;
	int		i;
	float	x;

	i = data->pos.y;
	i += add;
	f_add = data->pos.x - (f_slope * data->pos.y);
	while (1)
	{
		x = f_slope * (i + (add < 0)) + f_add;
		if (x < 0 || (int)x >= data->x_size || i < 0 || i >= data->y_size)
			return ((t_found){0x7FFFFFFF, 0});
		if (data->map[i][(int)x] == '1')
		{
			return ((t_found){get_distance((t_vector2f){x, i + (add < 0)},
				data->pos), x - (int)x});
		}
		i += add;
	}
}

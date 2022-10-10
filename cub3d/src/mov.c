/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:32 by syildiri          #+#    #+#             */
/*   Updated: 2022/10/10 11:03:29 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cube.h"

int	ft_collision_detect(t_data *data, t_vector2f pos)
{
	float	size;

	size = 0.2f;
	return (data->map[(int)(pos.y + size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x - size)] != '1'
		&& data->map[(int)(pos.y + size)][(int)(pos.x - size)] != '1');
}

void	ft_move(t_data *data, t_vector2f move)
{
	if (ft_collision_detect(data,
			(t_vector2f){data->pos.x + move.x, data->pos.y}))
		data->pos.x += move.x;
	if (ft_collision_detect(data,
			(t_vector2f){data->pos.x, data->pos.y + move.y}))
		data->pos.y += move.y;
}

int	ft_event_up(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 1;
	else if (key == 1)
		data->keys.s = 1;
	else if (key == 0)
		data->keys.a = 1;
	else if (key == 2)
		data->keys.d = 1;
	else if (key == 123)
		data->keys.left = 1;
	else if (key == 124)
		data->keys.right = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int	ft_event_down(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 0;
	else if (key == 1)
		data->keys.s = 0;
	else if (key == 0)
		data->keys.a = 0;
	else if (key == 2)
		data->keys.d = 0;
	else if (key == 123)
		data->keys.left = 0;
	else if (key == 124)
		data->keys.right = 0;
	return (0);
}

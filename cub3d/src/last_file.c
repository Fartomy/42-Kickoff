/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:01:07 by syildiri          #+#    #+#             */
/*   Updated: 2022/10/10 11:10:53 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cube.h"

int	get_characther_x(t_data2 *data)
{
	data->pos_cnt = 0;
	data->ltr_arg = 0;
	while (data->map[data->ltr_arg])
	{
		data->ltr_idx = 0;
		while (data->map[data->ltr_arg][data->ltr_idx])
		{
			if (data->map[data->ltr_arg] \
				[data->ltr_idx] == 'N')
				return (data->ltr_arg);
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'S')
				return (data->ltr_arg);
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'E')
				return (data->ltr_arg);
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'W')
				return (data->ltr_arg);
			data->ltr_idx++;
		}
		data->ltr_arg++;
	}
	return (-1);
}

float	character_angle(t_data2 *data)
{
	if (data->w_cnt)
		return (180.0f);
	if (data->e_cnt)
		return (0.0f);
	if (data->s_cnt)
		return (270.0f);
	if (data->n_cnt)
		return (90.0f);
	return (-1.f);
}

void	get_set_map_value(t_map *map, t_data2 *data)
{
	map->data = data->map;
	map->no = data->no[1];
	map->so = data->so[1];
	map->we = data->we[1];
	map->ea = data->ea[1];
	map->x = get_characther_y(data);
	map->y = get_characther_x(data);
	map->ang = character_angle(data);
	map->ceiling_color = data->ceil_rgb;
	map->floor_color = data->floor_rgb;
}

void	start_data(int arc, char **arv, t_map *map, t_data2 *data)
{
	if (arc == 2 && map_format_check(arv[1]))
	{
		set_value(data);
		map_oprt(data, arv[1]);
		map_features_check(data);
		map_ltr_cnt(data);
		map_all_check(data);
		map_wall_check(data);
		get_set_map_value(map, data);
	}
	else
	{
		write(2, "Error\nWrong Argument or Wrong Map Format!", 41);
		exit(1);
	}
}

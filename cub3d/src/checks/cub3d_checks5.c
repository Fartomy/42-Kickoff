/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:42:42 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/27 13:19:18 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	map_pos_check(t_data *data)
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
					data->pos_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'S')
					data->pos_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'E')
					data->pos_cnt++;
			else if (data->map[data->ltr_arg]\
					[data->ltr_idx] == 'W')
					data->pos_cnt++;
			data->ltr_idx++;
		}
		data->ltr_arg++;
	}
}

static void	map_ltr_check(t_data *data)
{
	bool pos_ctrl;

	pos_ctrl = false;
	if (data->n_cnt == 0 && data->s_cnt == 0 && \
		data->e_cnt == 0 && data->w_cnt == 0)
	{
		write(1, "Error\nStarting Position Not Found!", 34);
		exit(1);
	}
	if(data->n_cnt > 1 || data->s_cnt > 1 || \
		data->e_cnt > 1 || data->w_cnt > 1)
	{
		write(1, "Error\nMore Than One Starting Position!", 38);
		exit(1);
	}
	map_pos_check(data);
	if(data->pos_cnt > 1)
	{
		write(1, "Error\nMore Than One Starting Position!", 38);
		exit(1);
	}
}

void	map_ltr_cnt(t_data *data)
{
	while (data->map[data->ltr_arg])
	{
		data->ltr_idx = 0;
		while (data->map[data->ltr_arg][data->ltr_idx])
		{
			if (data->map[data->ltr_arg] \
				[data->ltr_idx] == 'N')
				data->n_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'S')
				data->s_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'E')
				data->e_cnt++;
			else if (data->map[data->ltr_arg]\
					[data->ltr_idx] == 'W')
				data->w_cnt++;
			data->ltr_idx++;
		}
		data->ltr_arg++;
	}
	map_ltr_check(data);
}
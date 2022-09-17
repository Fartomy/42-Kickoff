/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:44:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/17 23:54:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_value(t_data *data)
{
	data->pos_x = 12;
	data->pos_y = 5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->ground_x = 0;
	data->ground_y = 0.66;
	data->move_speed = 0.05;
	data->rot_speed = 0.05;
	data->nw_cnt = 1;
}
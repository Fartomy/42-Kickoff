/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:18:43 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 15:36:39 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sub_zero(t_data *data)
{
	data->score = 0;
	data->ttl_clc = 0;
	data->step_cnt = 1;
	data->nw_cnt = 1;
	data->img_idx = 0;
	data->img_arg = 0;
	data->ltr_check.c_cnt = 0;
	data->ltr_check.e_cnt = 0;
	data->ltr_check.p_cnt = 0;
	data->ltr_check.ltr_arg = 0;
	data->ltr_check.ltr_idx = 0;
	data->ltr_check.wal_chk_idx = 0;
	data->ltr_check.wall_chk_arg = 0;
}

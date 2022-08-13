/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:47:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/07/07 19:01:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_cnt_check(t_phdata *ph_data)
{
	if (ph_data->opt_eat_cnt != 0)
	{
		if (ph_data->eatcnt == ph_data->opt_eat_cnt)
			return (0);
	}
	return (1);
}

void	die_mssg(t_phdata *ph_data)
{
	pthread_mutex_lock(ph_data->lock);
	if (!(*(ph_data->is_dead)))
	{
		printf("%lu %d died\n", ph_data->simu_crnt_time, ph_data->id);
		*ph_data->is_dead = 1;
	}
	pthread_mutex_unlock(ph_data->lock);
}

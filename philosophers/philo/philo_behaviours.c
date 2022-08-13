/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behaviours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:34:02 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/07/08 15:46:55 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	simu_time_get(t_phdata *ph_data)
{
	struct timeval	strtsimu;

	gettimeofday(&strtsimu, NULL);
	ph_data->ms = (strtsimu.tv_sec * 1000) + (strtsimu.tv_usec / 1000);
	if (ph_data->start == 0)
		ph_data->start = ph_data->ms;
	ph_data->simu_crnt_time = ph_data->ms - ph_data->start;
}

int	fake_sleep(t_phdata *ph_data, int time)
{
	unsigned long int	crnt_frzn_time;

	simu_time_get(ph_data);
	crnt_frzn_time = ph_data->simu_crnt_time;
	while (ph_data->simu_crnt_time < crnt_frzn_time + time)
	{
		simu_time_get(ph_data);
		if (ph_data->simu_crnt_time > ph_data->ph_last_eat)
		{
			die_mssg(ph_data);
			return (1);
		}
		usleep(time);
	}
	return (0);
}

void	thinking(t_phdata *ph_data)
{
	simu_time_get(ph_data);
	pthread_mutex_lock(ph_data->lock);
	if (*ph_data->is_dead != 1)
		printf("%lu %d is thinking\n", ph_data->simu_crnt_time, ph_data->id);
	pthread_mutex_unlock(ph_data->lock);
	eating(ph_data);
}

void	sleeping(t_phdata *ph_data)
{
	simu_time_get(ph_data);
	pthread_mutex_lock(ph_data->lock);
	if (*ph_data->is_dead != 1)
		printf("%lu %d is sleeping\n", ph_data->simu_crnt_time, ph_data->id);
	pthread_mutex_unlock(ph_data->lock);
	fake_sleep(ph_data, ph_data->sleep_time);
	thinking(ph_data);
}

void	*eating(t_phdata *ph_data)
{
	if (eat_cnt_check(ph_data))
	{
		simu_time_get(ph_data);
		pthread_mutex_lock(ph_data->l_fork);
		pthread_mutex_lock(ph_data->r_fork);
		simu_time_get(ph_data);
		pthread_mutex_lock(ph_data->lock);
		if (*ph_data->is_dead != 1)
		{
			printf("%lu %d has taken a fork\
			\n%lu %d has taken a fork\n%lu %d is eating\n", \
			ph_data->simu_crnt_time, ph_data->id, \
			ph_data->simu_crnt_time, ph_data->id, \
			ph_data->simu_crnt_time, ph_data->id);
		}
		pthread_mutex_unlock(ph_data->lock);
		fake_sleep(ph_data, ph_data->eat_time);
		ph_data->eatcnt++;
		ph_data->ph_last_eat = ph_data->simu_crnt_time + ph_data->die_time;
		pthread_mutex_unlock(ph_data->r_fork);
		pthread_mutex_unlock(ph_data->l_fork);
		sleeping(ph_data);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:03:40 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/07/07 19:17:39 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mini_set(t_phdata *ph_data, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ph_data[i].id = i + 1;
		ph_data[i].nbr_of_philo = (unsigned long int)ft_atoi(av[1]);
		ph_data[i].die_time = (unsigned long int)ft_atoi(av[2]);
		ph_data[i].eat_time = (unsigned long int)ft_atoi(av[3]);
		ph_data[i].sleep_time = (unsigned long int)ft_atoi(av[4]);
		ph_data[i].ph_last_eat = (unsigned long int)ft_atoi(av[2]);
		ph_data[i].eatcnt = 0;
		ph_data[i].opt_eat_cnt = 0;
		if (av[5])
			ph_data[i].opt_eat_cnt = (unsigned long int)ft_atoi(av[5]);
		i++;
	}
}

int	arg_check(char **av)
{
	int	idx;
	int	arg;

	arg = 1;
	if (ft_atoi(av[1]) == 0)
		return (0);
	while (av[arg])
	{
		idx = 0;
		while (av[arg][idx])
		{
			if (av[arg][idx] >= '0' && av[arg][idx] <= '9')
				idx++;
			else
				return (0);
		}
		arg++;
	}
	return (1);
}

void	ft_mutex_init(t_phdata *ph_data, char **av)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (i < ft_atoi(av[1]))
		pthread_mutex_init(&forks[i++], NULL);
	ph_data->fork = forks;
}

void	set_value(t_phdata *ph_data, char **av)
{
	pthread_mutex_t		*locker;
	int					i;
	int					*die;
	int					*full;

	i = -1;
	die = malloc(sizeof(int));
	full = malloc(sizeof(int));
	locker = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(locker, NULL);
	*die = 0;
	*full = 0;
	mini_set(ph_data, av);
	while (++i < ft_atoi(av[1]))
	{
		ph_data[i].l_fork = &ph_data->fork[i];
		ph_data[i].r_fork = &ph_data->fork[i + 1];
		ph_data[i].lock = locker;
		ph_data[i].is_dead = die;
		ph_data[i].cnt = full;
	}
	ph_data[i - 1].r_fork = &ph_data->fork[0];
	ph_data->simu_crnt_time = 0;
	ph_data->ms = 0;
	ph_data->start = 0;
}

void	create_philo(t_phdata *ph_data)
{
	int	i;

	i = 0;
	while (i < ph_data->nbr_of_philo)
	{
		pthread_create(&ph_data[i].thread, NULL, \
		(void *)snuggle_up, &ph_data[i]);
		//pthread_detach(ph_data[i].thread);
		i += 2;
	}
	i = 1;
	usleep(100);
	while (i < ph_data->nbr_of_philo)
	{
		pthread_create(&ph_data[i].thread, NULL, \
		(void *)snuggle_up, &ph_data[i]);
		//pthread_detach(ph_data[i].thread);
		i += 2;
	}
}

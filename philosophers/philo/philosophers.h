/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:45:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/07/07 18:55:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//# define RED "\033[0;31m"
//# define GRN "\033[0;32m"
//# define YLW "\033[0;33m"
//# define PRP "\033[0;35m"
//# define WHT "\033[0;37m"

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct philosophers_atbs
{
	int							id;
	int							nbr_of_philo;
	int							die_time;
	int							eat_time;
	int							sleep_time;
	int							opt_eat_cnt;
	int							eatcnt;
	int							*is_dead;
	int							*cnt;
	unsigned long int			simu_crnt_time;
	unsigned long int			ph_last_eat;
	unsigned long int			ms;
	unsigned long int			start;
	pthread_t					thread;
	pthread_mutex_t				*lock;
	pthread_mutex_t				*fork;
	pthread_mutex_t				*r_fork;
	pthread_mutex_t				*l_fork;
}								t_phdata;

int		arg_check(char **av);
int		ft_atoi(const char *s);
void	*snuggle_up(void *ph_data);
void	ft_mutex_init(t_phdata *ph_data, char **av);
void	create_philo(t_phdata *ph_data);
void	set_value(t_phdata *ph_data, char **av);
void	*eating(t_phdata *ph_data);
void	sleeping(t_phdata *ph_data);
void	thinking(t_phdata *ph_data);
void	die_mssg(t_phdata *ph_data);
int		eat_cnt_check(t_phdata *ph_data);
int		fake_sleep(t_phdata *ph_data, int time);
void	ft_clean(t_phdata *ph_data);

#endif
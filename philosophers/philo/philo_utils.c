/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:03:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/07/07 18:50:13 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *s)
{
	int				nm;
	long int		tmp;

	nm = 1;
	tmp = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v' \
			|| *s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			nm = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		tmp = (tmp * 10) + (*s - '0') * nm;
		s++;
		if (tmp > 2147483647)
			return (-1);
		if (tmp < -2147483648)
			return (0);
	}
	return (tmp);
}

void	ft_clean(t_phdata *ph_data)
{
	free(ph_data->is_dead);
	free(ph_data->cnt);
	free(ph_data->lock);
	free(ph_data->fork);
	free(ph_data);
}

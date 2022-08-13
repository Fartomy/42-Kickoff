/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:06:10 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:37:08 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int i)
{
	i = 0;
	write(1, "Error\n", 7);
	exit(i);
}

void	is_it_sorted(t_pdata *data)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	bg_sort_min(data);
	while (i < data->a_len)
	{
		if (data->a_stack[i] == data->bg_sorted[i])
			d++;
		i++;
	}
	if (d == data->a_len)
	{
		ft_free(data);
		exit(0);
	}
}

void	is_it_same(t_pdata *data)
{
	int	i;
	int	d;
	int	x;

	d = 0;
	x = 0;
	while (d < data->a_len)
	{
		i = 0;
		while (i < data->a_len)
		{
			if (data->a_stack[d] == data->a_stack[i])
				x++;
			i++;
		}
		if (x > 1)
		{
			ft_free(data);
			ft_error(1);
		}
		else
			x = 0;
		d++;
	}
}

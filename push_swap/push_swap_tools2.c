/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:26:26 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:48:24 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_len(int max_len)
{
	int	i;

	i = 0;
	while (max_len)
	{
		max_len = max_len >> 1;
		i++;
	}
	return (i);
}

static int	find_idx(int idx_nbr, t_pdata *data)
{
	int	i;

	i = 0;
	while (idx_nbr != data->bg_sorted[i])
		i++;
	return (i);
}

void	slide_up_a(t_pdata *data)
{
	int	*nbr;
	int	i;

	i = 0;
	nbr = (int *)malloc(sizeof(int) * (data->a_len));
	while (i < data->a_len)
	{
		nbr[i] = data->a_stack[i + 1];
		i++;
	}
	i = 0;
	while (i < data->a_len)
	{
		data->a_stack[i] = nbr[i];
		i++;
	}
	free(nbr);
}

void	slide_up_b(t_pdata *data)
{
	int	*nbr;
	int	i;

	i = 0;
	nbr = (int *)malloc(sizeof(int) * (data->b_len));
	while (i < data->b_len)
	{
		nbr[i] = data->b_stack[i + 1];
		i++;
	}
	i = 0;
	while (i < data->b_len)
	{
		data->b_stack[i] = nbr[i];
		i++;
	}
	free(nbr);
}

void	sort_p(t_pdata *data)
{
	int	i;
	int	x;
	int	len;
	int	bit_cnt;

	i = 0;
	len = data->a_len;
	bg_sort_min(data);
	bit_cnt = bit_len(data->a_len);
	while (i < bit_cnt)
	{
		x = 0;
		while (x < len)
		{
			find_idx(data->a_stack[0], data);
			if ((find_idx(data->a_stack[0], data) >> i) & 1)
				ra(data);
			else
				pb(data);
			x++;
		}
		while (data->b_len)
			pa(data);
		i++;
	}
}

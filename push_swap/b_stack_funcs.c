/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:14:03 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/07 17:04:45 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_pdata *data)
{
	int	temp;

	if (data->b_len > 1)
	{
		temp = data->b_stack[0];
		data->b_stack[0] = data->b_stack[1];
		data->b_stack[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	pb(t_pdata *data)
{
	if (data->a_len > 0)
	{
		data->b_len++;
		slide_down_b(data);
		data->b_stack[0] = data->a_stack[0];
		slide_up_a(data);
		data->a_len--;
		write(1, "pb\n", 3);
	}
}

void	rb(t_pdata *data)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	len = data->b_len;
	while (--len)
	{
		temp = data->b_stack[i];
		data->b_stack[i] = data->b_stack[i + 1];
		data->b_stack[i + 1] = temp;
		i++;
	}
	write(1, "rb\n", 3);
}

void	rrb(t_pdata *data)
{
	int	len;
	int	idx;
	int	temp;

	len = data->b_len;
	idx = data->b_len - 1;
	while (--len)
	{
		temp = data->b_stack[idx];
		data->b_stack[idx] = data->b_stack[idx - 1];
		data->b_stack[idx - 1] = temp;
		idx--;
	}
	write(1, "rrb\n", 4);
}

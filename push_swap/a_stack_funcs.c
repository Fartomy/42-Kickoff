/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:13:17 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/07 17:04:29 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pdata *data)
{
	int	temp;

	if (data->a_len > 1)
	{
		temp = data->a_stack[0];
		data->a_stack[0] = data->a_stack[1];
		data->a_stack[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	pa(t_pdata *data)
{
	if (data->b_len > 0)
	{
		data->a_len++;
		slide_down_a(data);
		data->a_stack[0] = data->b_stack[0];
		slide_up_b(data);
		data->b_len--;
		write(1, "pa\n", 3);
	}
}

void	ra(t_pdata *data)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	len = data->a_len;
	while (--len)
	{
		temp = data->a_stack[i];
		data->a_stack[i] = data->a_stack[i + 1];
		data->a_stack[i + 1] = temp;
		i++;
	}
	write(1, "ra\n", 3);
}

void	rra(t_pdata *data)
{
	int	len;
	int	idx;
	int	temp;

	len = data->a_len;
	idx = data->a_len - 1;
	while (--len)
	{
		temp = data->a_stack[idx];
		data->a_stack[idx] = data->a_stack[idx - 1];
		data->a_stack[idx - 1] = temp;
		idx--;
	}
	write(1, "rra\n", 4);
}

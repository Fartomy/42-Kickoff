/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_and_b_stack_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:15:20 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/07 17:03:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_pdata *data)
{
	int	temp;

	if (data->a_len > 1)
	{
		temp = data->a_stack[0];
		data->a_stack[0] = data->a_stack[1];
		data->a_stack[1] = temp;
	}
	if (data->b_len > 1)
	{
		temp = data->b_stack[0];
		data->b_stack[0] = data->b_stack[1];
		data->b_stack[1] = temp;
	}
	write(1, "ss\n", 3);
}

void	rr(t_pdata *data)
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
	i = 0;
	len = data->b_len;
	while (--len)
	{
		temp = data->b_stack[i];
		data->b_stack[i] = data->b_stack[i + 1];
		data->b_stack[i + 1] = temp;
		i++;
	}
	write(1, "rr\n", 3);
}

void	rrr(t_pdata *data)
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
	len = data->b_len;
	idx = data->b_len - 1;
	while (--len)
	{
		temp = data->b_stack[idx];
		data->b_stack[idx] = data->b_stack[idx - 1];
		data->b_stack[idx - 1] = temp;
		idx--;
	}
	write(1, "rrr\n", 4);
}

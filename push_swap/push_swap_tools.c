/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:43:26 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:37:22 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alloction(t_pdata *data, int *nb)
{
	data->a_stack = (int *)malloc(sizeof(int) * (*nb));
	data->b_stack = (int *)malloc(sizeof(int) * (*nb));
	data->bg_sorted = (int *)malloc(sizeof(int) * (*nb));
}

void	storage_to_a_stack(t_pdata *data, char **av, int *ac, int *arg_cnt)
{
	char	**s;
	int		i;
	int		x;
	int		a;

	i = 0;
	x = 0;
	alloction(data, arg_cnt);
	while (i < (*ac - 1))
	{
		s = ft_split(av[i + 1], ' ');
		a = 0;
		while (s[a])
		{
			data->a_stack[x++] = ft_atoi(s[a]);
			free(s[a]);
			a++;
		}
		i++;
		free(s);
	}	
}

void	slide_down_b(t_pdata *data)
{
	int	*nbr;
	int	i;

	i = 0;
	nbr = (int *)malloc(sizeof(int) * data->b_len);
	while (i < data->b_len)
	{
		nbr[i] = data->b_stack[i];
		i++;
	}
	i = 0;
	while (i < data->b_len)
	{
		data->b_stack[i + 1] = nbr[i];
		i++;
	}
	free(nbr);
}

void	slide_down_a(t_pdata *data)
{
	int	*nbr;
	int	i;

	i = 0;
	nbr = (int *)malloc(data->a_len * sizeof(int));
	while (i < data->a_len)
	{
		nbr[i] = data->a_stack[i];
		i++;
	}
	i = 0;
	while (i < data->a_len)
	{
		data->a_stack[i + 1] = nbr[i];
		i++;
	}
	free(nbr);
}

void	bg_sort_min(t_pdata *data)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	len = data->a_len;
	while (i < len)
	{
		data->bg_sorted[i] = data->a_stack[i];
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		if (data->bg_sorted[i] > data->bg_sorted[i + 1])
		{
			temp = data->bg_sorted[i];
			data->bg_sorted[i] = data->bg_sorted[i + 1];
			data->bg_sorted[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

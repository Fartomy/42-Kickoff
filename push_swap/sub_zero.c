/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:51:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:38:12 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	subzero(t_pdata *data, int *nb)
{
	data->a_len = *nb;
	data->b_len = 0;
}

void	ft_free(t_pdata *data)
{
	free(data->a_stack);
	free(data->b_stack);
	free(data->bg_sorted);
}

int	arg_cnt_finder(char **av, int *ac)
{
	char	**s;
	int		x;
	int		i;
	int		c;

	i = 0;
	x = 0;
	c = 0;
	while (i < (*ac - 1))
	{
		s = ft_split(av[i + 1], ' ');
		x = 0;
		while (s[x])
		{
			free(s[x]);
			c++;
			x++;
		}
		i++;
		free(s);
	}
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:10:53 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:54:38 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pdata	data;
	int		arg_cnt;

	if (ac > 1)
	{
		arg_cnt = arg_cnt_finder(av, &ac);
		subzero(&data, &arg_cnt);
		storage_to_a_stack(&data, av, &ac, &arg_cnt);
		is_it_same(&data);
		is_it_sorted(&data);
		if (data.a_len == 3 || data.a_len == 5 || data.a_len == 2)
		{
			if (data.a_len == 2)
				ra(&data);
			else if (data.a_len == 3)
				for_three(&data);
			else
				for_five(&data);
		}
		else
			sort_p(&data);
	}
	else
		exit(0);
}

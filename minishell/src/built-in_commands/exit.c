/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:39:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_num_arg(char **parse, int *i, int *x)
{
	while (parse[*i])
	{
		*x = -1;
		while (parse[*i][++(*x)])
		{
			if (ft_isalpha(parse[*i][*x]))
			{
				printf("minishell: exit: %s: numeric argument required\n", \
						parse[*i]);
				g_dt.status = 255;
				exit(255);
			}
		}
		exit(ft_atoi(parse[*i]) % 256);
	}
}

static void	exit_too_many_arg(char **parse, int *i, int *x)
{
	while (parse[*i])
	{
		*x = -1;
		while (parse[*i][++(*x)])
		{
			if (ft_isalpha(parse[*i][*x]))
			{
				printf("minishell: exit: %s: numeric argument required\n", \
						parse[*i]);
				g_dt.status = 255;
				exit(255);
			}
		}
		printf("minishell: exit: too many arguments\n");
		g_dt.status = 1;
		exit(1);
	}
}

void	ft_exit(char **parse)
{
	int	i;
	int	x;

	i = 1;
	printf("exit\n");
	if (!parse[i])
		exit(0);
	else if (parse[i] && !parse[i + 1])
		exit_num_arg(parse, &i, &x);
	else
		exit_too_many_arg(parse, &i, &x);
}

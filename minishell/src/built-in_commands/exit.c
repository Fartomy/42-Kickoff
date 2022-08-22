/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:39:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/22 14:09:27 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **parse)
{
	printf("exit\n");
	
	int i;
	int x;

	i = 1;
	if(!parse[i])
		exit(0);
	else if(parse[i] && !parse[i + 1])
	{
		while (parse[i])
		{
			x = -1;
			while (parse[i][++x])
			{
				if(ft_isalpha(parse[i][x]))
				{
					printf("minishell: exit: %s: numeric argument required\n", parse[i]); 
					exit(255);
				}
			}
			exit(ft_atoi(parse[i]));
		}
	}
	else
	{
		while (parse[i])
		{
			x = -1;
			while (parse[i][++x])
			{
				if(ft_isalpha(parse[i][x]))
				{
					printf("minishell: exit: %s: numeric argument required\n", parse[i]); 
					exit(255);
				}
			}
			printf("minishell: exit: too many arguments\n");
			exit(1);
		}
	}
	
}
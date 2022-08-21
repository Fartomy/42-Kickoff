/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:39:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/21 17:11:39 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **parse)
{
	printf("exit\n");
	if(!parse[1])
		exit(0);
	else if(ft_isdigit(parse[1][0]) && !parse[2] && ft_isdigit(parse[1][0]) == 0)
		exit(ft_atoi(parse[1]));
	else if(ft_isdigit(parse[2][0]) && parse[2] && ft_isdigit(parse[1][0]) == 1)
	{
		printf("minishell: exit: too many arguments");
		exit(1);
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required", parse[1]);
		exit(255);
	}
}
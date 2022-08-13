/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:08:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/13 18:05:02 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(char **parse) // '$' için tekrardan dönülücek
{
	int i;
	
	i = 1;
    if (!(ft_strcmp(parse[1], "-n"))) // -n varsa
	{
		while (parse[++i])
		{
			printf("%s", parse[i]);
			if (parse[i] && parse[i + 1])
				printf(" ");
		}
	}
	else if (ft_strcmp(parse[1], "-n")) // -n yoksa
	{
		i = 0;
		while (parse[++i])
		{
			printf("%s", parse[i]);
			if (parse[i] && parse[i + 1])
				printf(" ");
		}
		printf("\n");
	}
}
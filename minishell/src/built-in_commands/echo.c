/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:08:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_if_n(char **parse, int *i)
{
	while (parse[++(*i)])
	{
		printf("%s", parse[*i]);
		if (parse[*i] && parse[*i + 1])
			printf(" ");
	}
	g_dt.status = 0;
}

static void	echo_if_not_n(char **parse, int *i)
{
	*i = 0;
	while (parse[++(*i)])
	{
		printf("%s", parse[*i]);
		if (parse[*i] && parse[*i + 1])
			printf(" ");
	}
	printf("\n");
	g_dt.status = 0;
}

void	ft_echo(char **parse)
{
	int	i;

	i = 1;
	if (!parse[1])
	{
		printf("\n");
		g_dt.status = 0;
	}
	else if (ft_strcmp(parse[1], "-n") == 0)
		echo_if_n(parse, &i);
	else if (ft_strcmp(parse[1], "-n"))
		echo_if_not_n(parse, &i);
}

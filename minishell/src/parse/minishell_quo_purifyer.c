/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quo_purifyer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:13:41 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/22 15:45:52 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int quo_finder(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if(s[i] == 34)
			return (2);
		else if(s[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

static int dbl_quo_cnt(char *s)
{
	int cnt;

	cnt = 0;
	while(*s)
	{
		if(*s == '"')
			cnt++;
		s++;
	}
	return(cnt);
}

char **quotes_purifyer(char **parse)
{
	int i;
	int i2;
	int x;
	int x2;
	char **prs;
	
	i = 0;
	x = 0;
	prs = ft_calloc(sizeof(char *), ft_arglen(parse) + 1);
	while(parse[i])
	{
		i2 = 0;
		x2 = 0;
		prs[x] = ft_calloc(sizeof(char), (ft_strlen(parse[i]) - dbl_quo_cnt(parse[i]) + 1));
		if(quo_finder(parse[i]) == 2)
		{	
			while(parse[i][i2])
			{
				if(parse[i][i2] != 34)
					prs[x][x2++] = parse[i][i2++];
				else
					i2++;
			}
		}
		else if(quo_finder(parse[i]) == 1)
		{
			while(parse[i][i2])
			{
				if(parse[i][i2] != 39)
					prs[x][x2++] = parse[i][i2++];
				else
					i2++;
			}
		}
		else
		{
			while(parse[i][i2])
				prs[x][x2++] = parse[i][i2++];
		}
		x++;
		i++;
	}
	ft_free(parse);
	return(prs);
}
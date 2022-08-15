/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:08:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/15 20:48:17 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *echo_env_helper(char *str)
{
	int i;
	int x;
	
	x = 0;
	i = 0;
	while (str[i] != '=')
		i++;
	if(str[i] == '=')
	{
		i++;
		while (str[i])
			str[x++] = str[i++];
	}
	str[x] = 0;
	return (str);
}

static	void echo_printenv_helper(char **parse, int *i, int *x)
{
	int 	a;
	int 	len;
	char	*env;
		
	a = ++(*x);
	while (parse[*i][a] && parse[*i][*x] != '$')
		a++;
	len = --a;
	env = ft_calloc(sizeof(char), a + 1);
	a = 0;
	while (parse[*i][*x] && parse[*i][*x] != '$')
		env[a++] = parse[*i][(*x)++];
	env[a] = 0;
	a = -1;
	while (data.env[++a])
	{
		if(ft_strncmp(data.env[a], env, len) == 0)
		{
			if(data.env[a][len] == '=')
			{
				free(env);
				env = ft_strdup(data.env[a]);
				env = echo_env_helper(env);
				printf("%s", env);
				free(env);
			}
			else
				free(env);
		}
	}
}

void    ft_echo(char **parse) // '$'ın tırnak işi' için tekrardan dönülücek
{
	int i;
	int x;
	
	i = 1;
    if ((ft_strcmp(parse[1], "-n")) == 0) // -n varsa
	{
		bool dolar_ctrl;
		
		while (parse[++i])
		{
			dolar_ctrl = false;
			x = -1;
			while (parse[i][++x])
			{
				if(parse[i][x] == '$')
				{
					dolar_ctrl = true;
					echo_printenv_helper(parse, &i, &x);
					/* if (parse[i] && parse[i + 1])
						printf(" "); */
				}
			}
			if(dolar_ctrl == false)
			{
				printf("%s", parse[i]);
				if (parse[i] && parse[i + 1])
					printf(" ");
			}
		}
	}
	else if (ft_strcmp(parse[1], "-n")) // -n yoksa
	{
		bool dolar_ctrl;
		
		i = 0;
		while (parse[++i])
		{
			dolar_ctrl = false;
			x = -1;
			while (parse[i][++x])
			{
				if(parse[i][x] == '$')
				{
					dolar_ctrl = true;
					echo_printenv_helper(parse, &i, &x);
					/* if (parse[i] && parse[i + 1])
						printf(" "); */
				}
			}
			if(dolar_ctrl == false)
			{
				printf("%s", parse[i]);
				if (parse[i] && parse[i + 1])
					printf(" ");
			}
		}
		printf("\n");
	}
}

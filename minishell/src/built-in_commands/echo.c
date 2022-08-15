/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:08:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/16 00:36:56 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char *env_searcher(char *bufenv, int buflen)
{
	int i;

	i = -1;
	while (data.env[++i])
	{
		if(ft_strncmp(data.env[i], bufenv, buflen) == 0)
		{
			if(data.env[i][buflen] == '=')
			{
				bufenv = ft_realloc(bufenv, ft_strlen(env_getter(data.env[i])));
				bufenv = env_getter(data.env[i]);
				return(bufenv);
			}
		}
	}
	return (NULL);
}

static	char *env_converter(char *str)
{
	int i;
	int x;
	char *s;

	s = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	i = -1;
	x = 0;
	while (str[++i])
	{
		if(str[i] == '$')
		{
			char *buf;
			int a;
			int len;
			int buflen;
			
			len = 0;
			a = i;
			a++;
			while (str[a] && str[a] != '$')
			{
				len++;
				a++;
			}
			buf = ft_calloc(sizeof(char), len + 1);
			buflen = len;
			a = i;
			a++;
			len = 0;
			while (str[a] && str[a] != '$')
				buf[len++] = str[a++];
			buf[len] = 0;
			buf = env_searcher(buf, buflen);
			len = 0;
			while (buf[len])
				s[x++] = buf[len++];
			free(buf);
			i += buflen;
		}
		else
			s[x++] = str[i];
	}
	s[x] = 0;
	return (s);	
}

void    ft_echo(char **parse)
{
	int i;
	
	i = 1;
    if ((ft_strcmp(parse[1], "-n")) == 0) // -n varsa
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

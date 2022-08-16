/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:08:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/16 18:09:42 by ftekdrmi         ###   ########.fr       */
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
				free(bufenv);
				bufenv = ft_strdup(env_getter(data.env[i]));
				return(bufenv);
			}
		}
	}
	return (NULL);
}

static char *env_cnv_helper(char *str, char *s, int *i, int *x)
{
	char *buf;
	int a;
	int len;
	int buflen;
	
	len = 0;
	a = *i;
	while (str[++a] && str[a] != '$')
		len++;
	buf = ft_calloc(sizeof(char), len + 1);
	buflen = len;
	a = *i;
	len = 0;
	while (str[++a] && str[a] != '$')
		buf[len++] = str[a];
	buf[len] = 0;
	buf = env_searcher(buf, buflen);
	if(buf != 0)
	{
		s[*x] = 0;
		s = ft_strjoin(s, buf);
		*x += ft_strlen(buf);
	}
	free(buf);	
	*i += buflen;
	return(s);
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
			s = env_cnv_helper(str, s, &i, &x);
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
			parse[i] = env_converter(parse[i]);
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
			parse[i] = env_converter(parse[i]);
			printf("%s", parse[i]);
			if (parse[i] && parse[i + 1])
				printf(" ");
		}
		printf("\n");
	}
}

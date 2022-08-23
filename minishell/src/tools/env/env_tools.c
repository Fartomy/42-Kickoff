/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:05:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/23 22:08:51 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char**	export_sorter(char **envp)
{
	int i;
	char *tmp;
	
	i = 0;
	while (envp[i])
	{
		if(envp[i + 1] && (envp[i][0] > envp[i + 1][0]))
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = -1;	
		}
		i++;
	}
	return (envp);
}

char 	*env_getter(char *str)
{
    int i;
    int x;
    int len;
    int a;
    char *temp;

	temp = NULL;
    a = 0;
    x = 0;
    i = 0;
    len = 0;
    while (str[i] != '=')
        i++;
    if(str[i] == '=')
    {
        a = i++;
        while(str[a++])
          len++;
        temp = ft_calloc(sizeof(char), len);
        while (str[i])
            temp[x++] = str[i++];
    }
    return (temp);
}

static	char *env_searcher(char *buf, int buflen)
{
	int i;

	i = -1;
	while (data.env[++i])
	{
		if(ft_strncmp(data.env[i], buf, buflen) == 0)
		{
			if(data.env[i][buflen] == '=')
			{	
				free(buf);
				buf = env_getter(data.env[i]);
				return(buf);
			}
		}
	}
	free(buf);
	return (NULL);
}

static	char *env_cnv_helper(char *str, char *s, int *i, int *x)
{
	char *buf;
	int a;
	int len;
	int buflen;
	
	len = 0;
	a = *i;
	while (str[++a] && str[a] != '$')
		len++;
	buf = ft_calloc(sizeof(char), len + 1); //FREEEEEEEEEEEEEEE
	buflen = len;
	a = *i;
	len = 0;
	while (str[++a] && str[a] != '$')
		buf[len++] = str[a];
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

char	*env_converter(char *str)
{
	int i;
	int x;
	char *s;

	s = ft_calloc(sizeof(char), ft_strlen(str) + 1); //FREEEEEEEEEEE
	i = -1;
	x = 0;
	while (str[++i])
	{
		if(str[i] == '$')
			s = env_cnv_helper(str, s, &i, &x);
		else
			s[x++] = str[i];
	}
	free(str);
	return (s);
}
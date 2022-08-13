/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_implt_funcs2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:14:32 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/12 16:54:14 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static    int    word_count(char const *str, char c)
{
    int    cnt;
    int i;

    cnt = 0;
    i = -1;
    while(str[++i])
    {
        if(str[i] == 34 && str[i] != 0)
        {
            cnt++;
            while(str[++i] != 34 && str[i] != 0)
                cnt++;
            cnt++;    
        }
        else if(str[i] == 39 && str[i] != 0)
        {
            cnt++;
            while(str[++i] != 39 && str[i] != 0)
                cnt++;
            cnt++;    
        }
        else if(str[i] != c)
            cnt++;
    }
    return (cnt);
}

static int pipe_cnt(char const *s, char c)
{
    int i;

    i = 0;
    while(s[i] == c)
        i++;
    return(i);
}

char    **ft_pipe_split(char const *s, char c)
{
    char    **res;
    int     index;
    int     two_index;
    int     word_len;

    if (!s)
        return (NULL);
    word_len = ft_strlen(s);
    res = (char **)ft_calloc(sizeof(char *), word_len + 1);
    index = -1;
    while (++index < word_len && *s != 0)
    {
        res[index] = (char *)ft_calloc(sizeof(char), word_count(s, c) + 1);
        two_index = 0;
        while (*s != c && *s != '\0')
        {
          if(*s == 34 && *s != 0)
          {
            res[index][two_index++] = *s++;
            while (*s != 34 && *s != '\0')
                res[index][two_index++] = *s++;
            if(*s == 34 && *s != '\0')
                res[index][two_index++] = *s++;
        }
          else if(*s == 39 && *s != 0)
          {
            res[index][two_index++] = *s++;
            while (*s != 39 && *s != '\0')
                res[index][two_index++] = *s++;
            if(*s == 39 && *s != '\0')
                res[index][two_index++] = *s++;
          }
          else
            res[index][two_index++] = *s++;
        }
        if(*s == c && *s != 0)
        {
            res[index++][two_index] = '\0';
            two_index = 0;
            res[index] = (char *)malloc(sizeof(char) * pipe_cnt(s, c) + 1);
            while(*s == c)
                res[index][two_index++] = *s++;
            res[index][two_index] = '\0';
        }
        else
          res[index][two_index] = '\0';  
    }
    res[index] = 0;
    return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_implt_funcs2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:14:32 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/02 12:17:54 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int word_count(char *s, char c)
{
    size_t cnt;

    cnt = 0;
    if (s[cnt] == 34 && s[cnt] != 0)
    {
        cnt++;
        while (s[cnt] != 34 && s[cnt] != 0)
            cnt++;
        if (s[cnt] != 0)
            cnt++;
    }
    else if (s[cnt] == 39 && s[cnt] != 0)
    {
        cnt++;
        while (s[cnt] != 39 && s[cnt] != 0)
            cnt++;
        if (s[cnt] != 0)
            cnt++;
    }
    else if (s[cnt] == c && s[cnt] != 0)
        cnt++;
    while (s[cnt] != '\0')
        cnt++;
    return (cnt);
}

static int len_word(char *s)
{
    size_t len;

    len = 0;
    while (*s != '\0')
    {
        if (*s == 34 && *s != 0)
        {
            len++;
            s++;
            while (*s != 34 && *s != 0)
            {
                len++;
                s++;
            }
            if (*s != 0)
                len++;
        }
        else if (*s == 39 && *s != 0)
        {
            len++;
            s++;
            while (*s != 39 && *s != 0)
            {
                len += 1;
                s++;
            }
            if (*s != 0)
                len += 1;
        }
        else if (*s != 0)
            len++;
        s++;
    }
    return (len);
}

char **ft_pipe_split( char *s, char c)
{
    int two_index;
    char **res;
    int index;
    int word_len;

    word_len = len_word(s);
    res = calloc(sizeof(char *), word_len + 1);
    index = -1;
    while (++index < word_len && *s != 0)
    {
        res[index] = ft_calloc(sizeof(char), word_count(s, c) + 1);
        two_index = 0;
        if (*s == 34 && *s != 0)
        {
            res[index][two_index++] = *s++;
            while (*s != 34 && *s)
                res[index][two_index++] = *s++;
            if (*s == 34 && *s)
                res[index][two_index++] = *s++;
            while (*s != '\0')
                res[index][two_index++] = *s++;
        }
        else if (*s == 39 && *s)
        {
            res[index][two_index++] = *s++;
            while (*s != 39 && *s)
                res[index][two_index++] = *s++;
            if (*s == 39 && *s)
                res[index][two_index++] = *s++;
            while (*s)
                res[index][two_index++] = *s++;
        }
        else if (*s == c)
            res[index][two_index++] = *s++;
        else
        {
            while (*s && *s != c)
            {
                if (*s == 34)
                {
                    res[index][two_index++] = *s++;
                    while (*s != 34 && *s)
                        res[index][two_index++] = *s++;
                    if (*s == 34)
                        res[index][two_index++] = *s++;
                }
                else if (*s == 39)
                {
                    res[index][two_index++] = *s++;
                    while (*s != 39 && *s)
                        res[index][two_index++] = *s++;
                    if (*s == 39)
                        res[index][two_index++] = *s++;
                }
                else
                    res[index][two_index++] = *s++;
            }
        }
    }
    return (res);
}

/*static    int    word_count(char const *str, char c) // OLD PIPE SPLIT
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

char    **ft_pipe_split_old(char const *s, char c)
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
            res[index] = (char *)ft_calloc(sizeof(char), pipe_cnt(s, c) + 1);
            while(*s == c)
                res[index][two_index++] = *s++;
        }
        else
          res[index][two_index] = '\0';  
    }
    return (res);
}*/
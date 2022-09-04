/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_implt_funcs3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 20:15:57 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int word_count(char *s)
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
    else if ((s[cnt] == '>' || s[cnt] == '<') && s[cnt] != 0)
    {
        if (s[cnt] == '>' && s[cnt + 1] == '>')
        {
            while (s[cnt] == '>')
                cnt++;
        }
        else if (s[cnt] == '<' && s[cnt + 1] == '<')
        {
            while (s[cnt] == '<')
                cnt++;
        }
        else
            cnt++;
    }
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

char **ft_symbol_split(char *s)
{
    int two_index;
    char **res;
    int index;
    int word_len;

    word_len = len_word(s);
    res = (char **)ft_calloc(sizeof(char *), word_len + 1);
    index = -1;
    while (++index < word_len && *s != 0)
    {
        res[index] = (char *)ft_calloc(sizeof(char), word_count(s) + 1);
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
        else if ((*s == '>' || *s == '<'))
        {
            if (*s == '>' && *(s + 1) == '>')
            {
                while (*s == '>')
                    res[index][two_index++] = *s++;
            }
            else if (*s == '<' && *(s + 1) == '<')
            {
                while (*s == '<')
                    res[index][two_index++] = *s++;
            }
            else
                res[index][two_index++] = *s++;
        }
        else
        {
            while (*s && *s != '>' && *s != '<')
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
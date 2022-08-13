/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_implt_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:46:01 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/12 20:00:09 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_arglen(char **arg)
{
    int i;

    i = 0;
    while(arg[i])
        i++;
    return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			t;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
    if (str2)
    {
        t = 0;
        while (str1[t] != '\0' && str2[t] != '\0' && str1[t] == str2[t])
            t++;
        return (str1[t] - str2[t]);
    }
    return (1);
}

static	size_t	word_count(char const *s, char c) // Ayıracak olacağı her argümanın sayısı Örnek("aa "bbb" cccc") -> 2, 3, 4
{
	size_t	cnt;

	cnt = 0;
    if(s[cnt] == 34 && s[cnt] != 0)
    {
        cnt++;
        while (s[cnt] != 34 && s[cnt] != 0)
            cnt++;
        if(s[cnt] != 0)
            cnt++;
    }
    else if(s[cnt] == 39 && s[cnt] != 0)
    {
        cnt++;
        while (s[cnt] != 39 && s[cnt] != 0)
            cnt++;
        if(s[cnt] != 0)
            cnt++;
    }
    else if((s[cnt] == '|' || s[cnt] == '>' || s[cnt] == '<') && s[cnt] != 0)
    {
        if(s[cnt] == '>' && s[cnt + 1] == '>')
        {
            while(s[cnt] == '>')
                cnt++;
        }
        else if(s[cnt] == '<' && s[cnt + 1] == '<')
        {
            while(s[cnt] == '<')
                cnt++;
        }
        else
            cnt++;
    }
	while (s[cnt] != '\0' && s[cnt] != c)
		cnt++;
	return (cnt);
}

static	size_t	len_word(char const *s, char c) // Girilen karakter(char c) haricinde ki karakter sayısı. 
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
        if(*s == 34 && *s != 0)
        {
            len++;
            s++;
            while(*s != 34 && *s != 0)
            {
                len++;
                s++;
            }
            if(*s != 0)
                len++;
        }
        else if(*s == 39 && *s != 0)
        {  
            len++;
            s++;
            while(*s != 39 && *s != 0)
            {
                len += 1;
                s++;
            }
            if(*s != 0)
                len += 1;
        }
		else if (*s != c)
			len++;
		s++;
	}
	return (len);
}

char	**ft_big_implt_split(char const *s, char c)
{
	size_t	two_index;
	char	**res;
	int	    index;
	int	    word_len;

	word_len = len_word(s, c);
	res = (char **)ft_calloc(sizeof(char *), word_len + 1);
	index = -1;
	while (++index < word_len && *s != 0)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = (char *)ft_calloc(sizeof(char), word_count(s, c) + 1);
		two_index = 0;
        if(*s == 34 && *s != 0)
        {
            res[index][two_index++] = *s++;
            while (*s != 34 && *s != '\0')
                res[index][two_index++] = *s++;
            if(*s == 34 && *s != '\0')
                res[index][two_index++] = *s++;
            while(*s != c && *s != '\0')
                res[index][two_index++] = *s++;
        }
        else if(*s == 39 && *s != 0)
        {
            res[index][two_index++] = *s++;
            while (*s != 39 && *s != '\0')
                res[index][two_index++] = *s++;
            if(*s == 39 && *s != '\0')
                res[index][two_index++] = *s++;
            while(*s != c && *s != '\0')
                res[index][two_index++] = *s++;
        }
        else if((*s == '|' || *s == '>' || *s == '<'))
        {
            if(*s == '>' && *(s + 1) == '>')
            {
                while(*s == '>')
                    res[index][two_index++] = *s++;
            }
            else if(*s == '<' && *(s + 1) == '<')
            {
                while(*s == '<')
                    res[index][two_index++] = *s++;
            }
            else
                res[index][two_index++] = *s++;
        }
        else
        {
		    while (*s != c && *s != '\0' && *s != '|' && *s != '>' && *s != '<')
			    res[index][two_index++] = *s++;
        }
		res[index][two_index] = '\0';
	}
	res[index] = 0;
	return (res);
}
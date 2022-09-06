/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_implt_funcs4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:21 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 22:14:13 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	word_count(char const *s, char c)
{
	size_t	cnt;

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
	while (s[cnt] != '\0' && s[cnt] != c)
		cnt++;
	return (cnt);
}

static void	len_word_helper(char **s, size_t *len)
{
	(*len)++;
	(*s)++;
	while (**s != 34 && **s != 0)
	{
		(*len)++;
		(*s)++;
	}
	if (**s != 0)
		(*len)++;
}

static size_t	len_word(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s == 34 && *s != 0)
			len_word_helper(&s, &len);
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
		else if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

static void	implt_split_helper(char **s, char *res, size_t *two_index, char c)
{
	res[(*two_index)++] = **s;
	(*s)++;
	while (**s != c && **s != '\0')
	{
		res[(*two_index)++] = **s;
		(*s)++;
	}
	if (**s != '\0')
	{
		res[(*two_index)++] = **s;
		(*s)++;
	}
}

char	**ft_implt_split(char *s, char c)
{
	size_t	two_index;
	char	**res;
	int		index;
	int		word_len;

	word_len = len_word(s, c);
	res = (char **)ft_calloc(sizeof(char *), word_len + 1);
	index = -1;
	while (++index < word_len && *s != 0)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = (char *)ft_calloc(sizeof(char), word_count(s, c) + 1);
		two_index = 0;
		if (*s == 34 && *s != 0)
			implt_split_helper(&s, res[index], &two_index, 34);
		else if (*s == 39 && *s != 0)
			implt_split_helper(&s, res[index], &two_index, 39);
		while (*s != c && *s != '\0')
			res[index][two_index++] = *s++;
	}
	return (res);
}

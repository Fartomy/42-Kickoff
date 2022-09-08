/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_symbol_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 15:01:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	word_count_helper(char *s, size_t *cnt)
{
	if (s[*cnt] == '>' && s[*cnt + 1] == '>')
	{
		while (s[*cnt] == '>')
			(*cnt)++;
	}
	else if (s[*cnt] == '<' && s[*cnt + 1] == '<')
	{
		while (s[*cnt] == '<')
			(*cnt)++;
	}
	else
		(*cnt)++;
}

static int	word_count(char *s)
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
	else if ((s[cnt] == '>' || s[cnt] == '<') && s[cnt] != 0)
		word_count_helper(s, &cnt);
	while (s[cnt] != '\0')
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

static int	len_word(char *s)
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
		else if (*s != 0)
			len++;
		s++;
	}
	return (len);
}

char	**ft_symbol_split(char *s)
{
	int		two_index;
	char	**res;
	int		index;
	int		word_len;

	word_len = len_word(s);
	res = (char **)ft_calloc(sizeof(char *), word_len + 1);
	index = -1;
	while (++index < word_len && *s != 0)
	{
		res[index] = (char *)ft_calloc(sizeof(char), word_count(s) + 1);
		two_index = 0;
		if (*s == 34 && *s != 0)
			symbol_spl_helper(&s, res[index], &two_index, 34);
		else if (*s == 39 && *s)
			symbol_spl_helper(&s, res[index], &two_index, 39);
		else if ((*s == '>' || *s == '<'))
			symbol_spl_helper2(&s, res[index], &two_index);
		else
			symbol_spl_helper3(&s, res[index], &two_index);
	}
	return (res);
}

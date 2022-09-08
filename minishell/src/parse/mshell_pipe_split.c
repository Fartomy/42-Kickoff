/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_pipe_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:14:32 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:28:06 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	word_count(char *s, char c)
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
	else if (s[cnt] == c && s[cnt] != 0)
		cnt++;
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

char	**ft_pipe_split(char *s, char c)
{
	int		two_index;
	char	**res;
	int		index;
	int		word_len;

	word_len = len_word(s);
	res = calloc(sizeof(char *), word_len + 1);
	index = -1;
	while (++index < word_len && *s != 0)
	{
		res[index] = ft_calloc(sizeof(char), word_count(s, c) + 1);
		two_index = 0;
		if (*s == 34 && *s != 0)
			pipe_spl_helper(&s, res[index], &two_index, 34);
		else if (*s == 39 && *s)
			pipe_spl_helper(&s, res[index], &two_index, 39);
		else if (*s == c)
			res[index][two_index++] = *s++;
		else
			pipe_spl_helper2(&s, res[index], &two_index, c);
	}
	return (res);
}

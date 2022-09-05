/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:14:32 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/05 18:46:08 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	len_world_helper(size_t *len, char **s)
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

static int	word_count(char *s, char c)
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
			len_world_helper(&len, &s);
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

char **ft_pipe_split(char *s, char c)
{
	t_pipe_split_vars	psp;

	psp.i = 0;
	psp.word_len = len_word(s);
	psp.res = ft_calloc(sizeof(char *), psp.word_len + 1);
	psp.index = -1;
	while (++psp.index < psp.word_len && s[psp.i] != 0)
	{
		psp.res[psp.index] = ft_calloc(sizeof(char), word_count(s, c) + 1);
		psp.two_index = 0;
		if (s[psp.i] == 34 && s[psp.i] != 0)
			ft_pipe_sp_helper(&psp, s);
		else if (s[psp.i] == 39 && s[psp.i])
			ft_pipe_sp_helper2(&psp, s);
		else if (s[psp.i] == c)
			psp.res[psp.index][psp.two_index++] = s[psp.i++];
		else
			ft_pipe_sp_helper3(&psp, s, c);
	}
	return (psp.res);
}

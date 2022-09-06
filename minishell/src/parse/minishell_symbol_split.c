/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_symbol_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 12:59:09 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	word_count_helper(char *s, size_t *cnt)
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
		word_count_helper(s, &cnt);
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

static void	len_world_helper(char **s, size_t *len)
{
	(*len)++;
	(*s)++;
	while (**s != 34 && **s != 0)
	{
		len++;
		(*s)++;
	}
	if (**s != 0)
		(*len)++;
}

static int len_word(char *s)
{
	size_t len;

	len = 0;
	while (*s != '\0')
	{
		if (*s == 34 && *s != 0)
			len_world_helper(&s, &len);
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

static void symbol_spl_helper(t_symbol_spl_vars *sp, char *s)
{
	sp->res[sp->index][sp->two_index++] = s[sp->i++];
	while (s[sp->i] != 34 && s[sp->i])
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
	if (s[sp->i] == 34 && s[sp->i])
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
	while (s[sp->i] != '\0')
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
}

static void symbol_spl_helper2(t_symbol_spl_vars *sp, char *s)
{
	sp->res[sp->index][sp->two_index++] = s[sp->i++];
	while (s[sp->i] != 39 && s[sp->i])
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
	if (s[sp->i] == 39 && s[sp->i])
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
	while (s[sp->i])
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
}

static void symbol_spl_helper3(t_symbol_spl_vars *sp, char *s)
{
	if (s[sp->i] == '>' && s[sp->i + 1] == '>')
	{
		while (s[sp->i] == '>')
			sp->res[sp->index][sp->two_index++] = s[sp->i++];
	}
	else if (s[sp->i] == '<' && s[sp->i + 1] == '<')
	{
		while (s[sp->i] == '<')
			sp->res[sp->index][sp->two_index++] = s[sp->i++];
	}
	else
		sp->res[sp->index][sp->two_index++] = s[sp->i++];
}

static void symbol_spl_helper4(t_symbol_spl_vars *sp, char *s)
{
	while (s[sp->i] && s[sp->i] != '>' && s[sp->i] != '<')
	{
		if (s[sp->i] == 34)
		{
			sp->res[sp->index][sp->two_index++] = s[sp->i++];
			while (s[sp->i] != 34 && s[sp->i])
				sp->res[sp->index][sp->two_index++] = s[sp->i++];
			if (s[sp->i] == 34)
				sp->res[sp->index][sp->two_index++] = s[sp->i++];
		}
		else if (s[sp->i] == 39)
		{
			sp->res[sp->index][sp->two_index++] = s[sp->i++];
			while (s[sp->i] != 39 && s[sp->i])
				sp->res[sp->index][sp->two_index++] = s[sp->i++];
			if (s[sp->i] == 39)
				sp->res[sp->index][sp->two_index++] = s[sp->i++];
		}
		else
			sp->res[sp->index][sp->two_index++] = s[sp->i++];
	}
}

char **ft_symbol_split(char *s)
{
	t_symbol_spl_vars spv;

	spv.i = 0;
	spv.word_len = len_word(s);
	spv.res = (char **)ft_calloc(sizeof(char *), spv.word_len + 1);
	spv.index = -1;
	while (++spv.index < spv.word_len && s[spv.i] != 0)
	{
		spv.res[spv.index] = (char *)ft_calloc(sizeof(char), word_count(s) + 1);
		spv.two_index = 0;
		if (s[spv.i] == 34 && s[spv.i] != 0)
			symbol_spl_helper(&spv, s);
		else if (s[spv.i] == 39 && s[spv.i])
			symbol_spl_helper2(&spv, s);
		else if ((s[spv.i] == '>' || s[spv.i] == '<'))
			symbol_spl_helper3(&spv, s);
		else
			symbol_spl_helper4(&spv, s);
	}
	return (spv.res);
}
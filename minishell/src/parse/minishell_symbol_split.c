/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_symbol_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 12:29:29 by ftekdrmi         ###   ########.fr       */
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
	t_symbol_spl_vars	spv;

	spv.i = 0;
	spv.word_len = len_word(s);
	spv.res = (char **)ft_calloc(sizeof(char *), spv.word_len + 1);
	spv.index = -1;
	while (++spv.index < spv.word_len && s[spv.i] != 0)
	{
		spv.res[spv.index] = (char *)ft_calloc(sizeof(char), word_count(s) + 1);
		spv.two_index = 0;
		if (s[spv.i] == 34 && s[spv.i] != 0)
		{
			spv.res[spv.index][spv.two_index++] = s[spv.i++];
			while (s[spv.i] != 34 && s[spv.i])
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
			if (s[spv.i] == 34 && s[spv.i])
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
			while (s[spv.i] != '\0')
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
		}
		else if (s[spv.i] == 39 && s[spv.i])
		{
			spv.res[spv.index][spv.two_index++] = s[spv.i++];
			while (s[spv.i] != 39 && s[spv.i])
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
			if (s[spv.i] == 39 && s[spv.i])
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
			while (s[spv.i])
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
		}
		else if ((s[spv.i] == '>' || s[spv.i] == '<'))
		{
			if (s[spv.i] == '>' && s[spv.i + 1] == '>')
			{
				while (s[spv.i] == '>')
					spv.res[spv.index][spv.two_index++] = s[spv.i++];
			}
			else if (s[spv.i] == '<' && s[spv.i + 1] == '<')
			{
				while (s[spv.i] == '<')
					spv.res[spv.index][spv.two_index++] = s[spv.i++];
			}
			else
				spv.res[spv.index][spv.two_index++] = s[spv.i++];
		}
		else
		{
			while (s[spv.i] && s[spv.i] != '>' && s[spv.i] != '<')
			{
				if (s[spv.i] == 34)
				{
					spv.res[spv.index][spv.two_index++] = s[spv.i++];
					while (s[spv.i] != 34 && s[spv.i])
						spv.res[spv.index][spv.two_index++] = s[spv.i++];
					if (s[spv.i] == 34)
						spv.res[spv.index][spv.two_index++] = s[spv.i++];
				}
				else if (s[spv.i] == 39)
				{
					spv.res[spv.index][spv.two_index++] = s[spv.i++];
					while (s[spv.i] != 39 && s[spv.i])
						spv.res[spv.index][spv.two_index++] = s[spv.i++];
					if (s[spv.i] == 39)
						spv.res[spv.index][spv.two_index++] = s[spv.i++];
				}
				else
					spv.res[spv.index][spv.two_index++] = s[spv.i++];
			}
		}
	}
	return (spv.res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:23:00 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:28:30 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *s)
{
	int				nm;
	long long int	tmp;

	nm = 1;
	tmp = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			nm = -1;
		if (*(s + 1) != '\0')
			s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		tmp = (tmp * 10) + (*s - '0') * nm;
		s++;
		if (tmp > 2147483647)
			ft_error(1);
		if (tmp < -2147483648)
			ft_error(0);
	}
	if (*s != 0)
		ft_error(0);
	return (tmp);
}

static	size_t	word_count(char const *str, char chr)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != '\0' && str[cnt] != chr)
		cnt++;
	return (cnt);
}

static	size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	if (!s)
		return (NULL);
	word_len = len_word(s, c);
	res = (char **)malloc(sizeof(char *) * word_len + 1);
	if (res == NULL)
		return (NULL);
	index = 0;
	while (index < word_len)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = (char *)malloc(sizeof(char) * word_count(s, c) + 1);
		two_index = 0;
		while (*s != c && *s != '\0')
		res[index][two_index++] = *s++;
		res[index][two_index] = '\0';
		index++;
	}
	res[index] = NULL;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:54:35 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 13:44:06 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_map_free(void *f)
{
	free (f);
	return (NULL);
}

char	*get_map(int fd, char *av)
{
	char	*map_s;
	int		bufsize;

	bufsize = map_lenght(av);
	map_s = (char *)ft_calloc(bufsize + 1, sizeof(char));
	if (!map_s)
		return (0);
	read(fd, map_s, bufsize);
	map_s[bufsize] = 0;
	if (!*map_s)
		return (get_map_free(map_s));
	return (map_s);
}

static	size_t	word_count(char const *str, char chr)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != '\0' && str[cnt] != chr)
		cnt++;
	if (str[cnt] == 0)
		cnt--;
	return (cnt);
}

static	size_t	len_word(char const *s, char c, t_data *data)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == '\n')
			data->nw_cnt++;
		len++;
	}
	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c, t_data *data)
{
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	word_len = len_word(s, c, data);
	data->row_cnt = word_len;
	res = (char **)ft_calloc(word_len + 1, sizeof(char *));
	if (res == 0)
		return (0);
	index = -1;
	while (++index < word_len)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = (char *)ft_calloc(word_count(s, c) + 1, sizeof(char));
		two_index = 0;
		while (*s != c && *s != '\0')
			res[index][two_index++] = *s++;
		res[index][two_index] = 0;
	}
	data->row_len = two_index;
	res[index] = 0;
	return (res);
}

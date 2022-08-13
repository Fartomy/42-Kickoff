/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:58:31 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/30 16:42:44 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*after_line(char *s)
{
	char	*str;
	int		idx;
	int		idx2;

	idx = 0;
	idx2 = 0;
	while (s[idx] != 0 && s[idx] != '\n')
		idx++;
	if (!s[idx])
	{
		free(s);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) - idx + 1));
	if (!str)
		return (0);
	idx++;
	while (s[idx] != 0)
		str[idx2++] = s[idx++];
	str[idx2] = 0;
	free(s);
	return (str);
}

char	*get_first_line(char *s)
{
	char	*str;
	int		idx;

	idx = 0;
	if (!s[idx])
		return (0);
	while (s[idx] != '\n' && s[idx] != 0)
		idx++;
	str = malloc(sizeof(char) * idx + 2);
	if (!str)
		return (0);
	idx = 0;
	while (s[idx] != 0 && s[idx] != '\n')
	{
		str[idx] = s[idx];
		idx++;
	}
	if (s[idx] == '\n')
	{
		str[idx] = '\n';
		idx++;
	}
	str[idx] = 0;
	return (str);
}

char	*fileread(int fd, char *s)
{
	char	*buff;
	int		count;

	count = 999999;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!ft_chrfind(s, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (0);
		}
		buff[count] = 0;
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*str[256];
	char			*first_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = fileread(fd, str[fd]);
	if (!str[fd])
		return (0);
	first_line = get_first_line(str[fd]);
	str[fd] = after_line(str[fd]);
	return (first_line);
}

/*int main()
{
	int fd;

	fd = open("deneme.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%d\n", fd);

	fd = open("deneme2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%d\n", fd);

	fd = open("deneme3.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%d\n", fd);
	return (0);
}*/
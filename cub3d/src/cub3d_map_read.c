/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:34:48 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/09 17:11:05 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cub3d.h"

void	*map_get_free(void *f)
{
	free (f);
	return (NULL);
}

int	map_lenght(char *arv)
{
	int		map_cnt;
	int		fd;
	int		i;
	char	s;

	map_cnt = 0;
	fd = open(arv, O_RDONLY);
	if (fd < 0)
		return (0);
	i = read(fd, &s, 1);
	while (i > 0)
	{
		i = read(fd, &s, 1);
		map_cnt++;
	}
	close(fd);
	if (map_cnt == 0)
	{
		write(1, "Error\nEmpty Map!", 16);
		exit(1);
	}
	return (map_cnt);
}

char	*map_get(int fd, char *arv)
{
	char	*map_s;
	int		bufsize;

	bufsize = map_lenght(arv);
	map_s = (char *)ft_calloc(bufsize + 1, sizeof(char));
	if (!map_s)
		return (0);
	read(fd, map_s, bufsize);
	map_s[bufsize] = 0;
	if (!*map_s)
		return (map_get_free(map_s));
	return (map_s);
}

void	map_oprt(t_data2 *data, char *arv)
{
	char	*map_s;
	int		fd;

	(void)data;
	fd = open(arv, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nWrong Map File Name!", 27);
		exit(1);
	}
	map_s = map_get(fd, arv);
	close(fd);
	data->map_and_ftrs = ft_split(map_s, '\n');
	free(map_s);
}

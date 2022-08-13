/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:47:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 20:22:17 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lenght(char *av)
{
	int		map_cnt;
	int		fd;
	int		i;
	char	s;

	map_cnt = 0;
	fd = open(av, O_RDONLY);
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
		ft_printf("Error\nEmpty Map!");
		exit(0);
	}
	return (map_cnt);
}

void	map_read(t_data *data, char *av)
{
	char	*map_s;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nWrong Map File Name!", 27);
		exit(1);
	}
	map_s = get_map(fd, av);
	data->map = ft_split(map_s, '\n', data);
	free(map_s);
}

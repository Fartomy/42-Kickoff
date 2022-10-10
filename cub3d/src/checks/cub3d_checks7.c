/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:53:23 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/09 16:00:46 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/cub3d.h"

void	rgb_clr_code_err_msg(void)
{
	write(2, "Error\nRGB Color Code is Wrong!", 30);
	exit(1);
}

void	rgb_storage(t_data2 *data, char *idf, char *rgb)
{
	char	**s;
	int		i;

	i = -1;
	s = ft_split(rgb, ',');
	if (ft_strncmp(idf, "F", 1) == 0)
	{
		while (++i < 3)
			data->floor[i] = ft_atoi(s[i]);
	}
	else if (ft_strncmp(idf, "C", 1) == 0)
	{
		while (++i < 3)
			data->ceil[i] = ft_atoi(s[i]);
	}
	ft_arg_free(s);
}

static void	is_wall_open(int i, char *big_line)
{
	while (big_line[i])
	{
		if (big_line[i] == '0')
		{
			write(2, "Error\nRight Vertical Wall is Wrong!", 35);
			exit(1);
		}
		i++;
	}
}

static void	rght_wll_err_msg(void)
{
	write(2, "Error\nRight Vertical Wall is Wrong!", 35);
	exit(1);
}

void	right_vertical_check(t_data2 *data)
{
	int	size_sml;

	data->wal_chk_arg = -1;
	while (data->map[++data->wal_chk_arg] && data->map[data->wal_chk_arg + 1])
	{
		if (ft_strlen(data->map[data->wal_chk_arg]) > \
			ft_strlen(data->map[data->wal_chk_arg + 1]))
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg + 1]);
			is_wall_open(size_sml, data->map[data->wal_chk_arg]);
		}
		else if (ft_strlen(data->map[data->wal_chk_arg]) < \
				ft_strlen(data->map[data->wal_chk_arg + 1]))
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg]);
			is_wall_open(size_sml, data->map[data->wal_chk_arg + 1]);
		}
		else
		{
			size_sml = ft_strlen(data->map[data->wal_chk_arg]);
			if (data->map[data->wal_chk_arg][size_sml - 1] != '1' || \
				data->map[data->wal_chk_arg + 1][size_sml - 1] != '1')
				rght_wll_err_msg();
		}
	}
}

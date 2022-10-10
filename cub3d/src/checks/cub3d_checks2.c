/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:00:22 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/09 16:00:46 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/cub3d.h"

static void	idf_ea_ctrl(t_data2 *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "EA", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}
}

static void	idf_we_ctrl(t_data2 *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "WE", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}
}

static void	idf_so_ctrl(t_data2 *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "SO", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

static void	idf_no_ctrl(t_data2 *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "NO", 2) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

void	map_ftrs_is_same_check(t_data2 *data)
{
	idf_no_ctrl(data);
	idf_so_ctrl(data);
	idf_we_ctrl(data);
	idf_ea_ctrl(data);
	idf_f_ctrl(data);
	idf_c_ctrl(data);
}

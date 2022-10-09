/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:28:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/09 14:43:20 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	idf_f_ctrl(t_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "F", 1) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

void	idf_c_ctrl(t_data *data)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "C", 1) == 0)
			cnt++;
		if (cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			exit(1);
		}
	}	
}

void	map_ftrs_element_check(t_data *data)
{
	char	**str;
	int		i;

	i = -1;
	while (data->map_ftrs[++i])
	{
		str = ft_split(data->map_ftrs[i], ' ');
		if (ft_arglen(str) != 2)
		{
			write(2, "Error\nToo Much Arguments!", 25);
			exit(1);
		}
		ft_arg_free(str);
	}
}

static void	path_storage(t_data *data,	char **str)
{
	if(!ft_strncmp(str[0], "NO", 2))
	{
		data->no[0] = ft_strdup(str[0]);
		data->no[1] = ft_strdup(str[1]);
		data->no[2] = 0;
	}
	else if(!ft_strncmp(str[0], "SO", 2))
	{
		data->so[0] = ft_strdup(str[0]);
		data->so[1] = ft_strdup(str[1]);
		data->so[2] = 0;
	}
	else if(!ft_strncmp(str[0], "WE", 2))
	{
		data->we[0] = ft_strdup(str[0]);
		data->we[1] = ft_strdup(str[1]);
		data->we[2] = 0;
	}
	else if(!ft_strncmp(str[0], "EA", 2))
	{
		data->ea[0] = ft_strdup(str[0]);
		data->ea[1] = ft_strdup(str[1]);
		data->ea[2] = 0;
	}
}

void	map_ftrs_path_check(t_data *data)
{
	char	**str;
	int		i;
	int		x;

	x = 0;
	i = -1;
	while (data->map_ftrs[++i])
	{
		if (!ft_strncmp(data->map_ftrs[i], "NO", 2) || \
			!ft_strncmp(data->map_ftrs[i], "SO", 2) || \
			!ft_strncmp(data->map_ftrs[i], "WE", 2) || \
			!ft_strncmp(data->map_ftrs[i], "EA", 2))
		{
			str = ft_split(data->map_ftrs[i], ' ');
			if (open(str[1], O_RDWR, 0777) == -1)
			{
				write(2, "Error\nPath is Wrong!", 20);
				ft_arg_free(str);
				exit(1);
			}
			path_storage(data, str);
			ft_arg_free(str);
			x++;
		}
	}
	map_ftrs_rgb_check(data, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:28:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/30 14:50:22 by ftekdrmi         ###   ########.fr       */
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

static void	paths_free(t_data *data, int i)
{
	int	x;

	x = 0;
	while (x < i)
		free(data->paths[x++]);
}

void	map_ftrs_path_check(t_data *data)
{
	char	**str;
	int		i;

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
				paths_free(data, i);
				exit(1);
			}
			data->paths[i] = ft_calloc(ft_strlen(str[1]), sizeof(char));
			ft_strcpy(data->paths[i], str[1]);
			ft_arg_free(str);
		}
	}
	map_ftrs_rgb_check(data, i);
}

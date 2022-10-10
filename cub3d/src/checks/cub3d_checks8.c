/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:04:00 by syildiri          #+#    #+#             */
/*   Updated: 2022/10/10 11:04:01 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/cub3d.h"

void	map_ftrs_path_check(t_data2 *data)
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
				exit(1);
			}
			path_storage(data, str);
			ft_arg_free(str);
		}
	}
	map_ftrs_rgb_check(data, i);
}

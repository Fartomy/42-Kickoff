/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:45 by syildiri          #+#    #+#             */
/*   Updated: 2022/10/10 11:02:03 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cube.h"

void	ft_swap(char **a, char *b)
{
	char	*tmp;

	tmp = *a;
	*a = b;
	free(tmp);
}

void	free_split(char **str)
{
	int	i;

	(void)str;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	get_file_color(char *color_str)
{
	char	**rgb;
	int		result;

	rgb = ft_split(color_str, ',');
	result = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	free_split(rgb);
	return (result);
}

void	image_control(t_data *data)
{
	if (!data->imgs[0].img || !data->imgs[1].img
		|| !data->imgs[2].img || !data->imgs[3].img)
	{
		ft_putstr_fd("image error!\n", 2);
		exit(-1);
	}
}

void	get_file_args(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx, map->no,
			&data->imgs[0].width, &data->imgs[0].height);
	data->imgs[1].img = mlx_xpm_file_to_image(data->mlx, map->so,
			&data->imgs[1].width, &data->imgs[1].height);
	data->imgs[2].img = mlx_xpm_file_to_image(data->mlx, map->ea,
			&data->imgs[2].width, &data->imgs[2].height);
	data->imgs[3].img = mlx_xpm_file_to_image(data->mlx, map->we,
			&data->imgs[3].width, &data->imgs[3].height);
	image_control(data);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img,
			&data->imgs[0].bbp, &data->imgs[0].line_len, &data->imgs[0].endian);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img,
			&data->imgs[1].bbp, &data->imgs[1].line_len, &data->imgs[1].endian);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img,
			&data->imgs[2].bbp, &data->imgs[2].line_len, &data->imgs[2].endian);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img,
			&data->imgs[3].bbp, &data->imgs[3].line_len, &data->imgs[3].endian);
	data->floor_color = map->floor_color;
	data->ceil_color = map->ceiling_color;
}

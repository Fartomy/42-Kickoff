/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:43:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 20:43:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_key(int keycode, void *data)
{
	if (keycode == 13)
		key_w(data);
	else if (keycode == 1)
		key_s(data);
	else if (keycode == 2)
		key_d(data);
	else if (keycode == 0)
		key_a(data);
	else if (keycode == 53)
		key_esc(data);
	return (keycode);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		width;

	if (ac == 2 && map_name_check(av[1]))
	{
		sub_zero(&data);
		map_read(&data, av[1]);
		map_rectangle_check(&data);
		map_ltr_check(&data);
		map_wall_check(&data);
		map_newline_check(&data);
		map_all_check(&data);
		width = data.row_len * 64;
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, width, data.row_cnt * 64, "SOLONG");
		images_create(&data);
		map_put_image(&data);
		mlx_hook(data.win, 2, 1L << 0, find_key, &data);
		mlx_hook(data.win, 17, 0, clean_up, &data);
		mlx_loop(data.mlx);
	}
	else
		write(1, "Error\nWrong Argument or Wrong File Extension!", 46);
	exit(1);
}

// 1- window exit button event (OK)
// 2- leak hataları (OK)
// 3- norm controls (OK)
// 4- map.ber boşken hata vermiyor düzelt (OK)
// 5- ft_prntf'i at (OK)
// 6- fotoları değiştir (sarma yatak)
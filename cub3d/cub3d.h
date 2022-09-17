/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:35:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/17 18:18:05 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# define WIDTH 1920
# define HEIGHT 1080

# include "mlx/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_data
{
	double	ground_x;
	double	ground_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;

	void	*mlx_ptr;
	void	*mlx_win_ptr;
	
}	t_data;


void	set_value(t_data *data);
void	map_oprt(t_data *data, char *arv);
int		map_format_check(char *av);

#endif
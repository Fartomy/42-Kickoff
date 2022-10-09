/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:35:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/10/09 15:21:20 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1920
# define HEIGHT 1080

# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"

# define FLOOR	'F'
# define CEIL	'C'

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_data
{
	double	pos_x;
	double	pos_y;

	void	*mlx_ptr;
	void	*mlx_win_ptr;

	char	**map_and_ftrs;
	char	*no[3];
	char	*so[3];
	char	*we[3];
	char	*ea[3];

	char	*map_ftrs[6];
	char	**map;

	int		floor[3];
	int		ceil[3];
	int		floor_rgb;
	int		ceil_rgb;

	int		wal_chk_idx;
	int		wal_chk_arg;
	int		ltr_arg;
	int		ltr_idx;

	int		n_cnt;
	int		s_cnt;
	int		e_cnt;
	int		w_cnt;
	int		pos_cnt;
}	t_data;

void	map_features_check(t_data *data);
void	map_ftrs_is_same_check(t_data *data);
void	map_ftrs_element_check(t_data *data);
void	map_ftrs_path_check(t_data *data);
void	map_ftrs_rgb_check(t_data *data, int i);
void	map_check(t_data *data, int i);
void	map_wall_check(t_data *data);
void	map_all_check(t_data *data);
void	map_ltr_cnt(t_data *data);
void	right_vertical_check(t_data *data);
void	idf_f_ctrl(t_data *data);
void	idf_c_ctrl(t_data *data);

int		map_format_check(char *av);
int		ft_arglen(char **arg);

void	ft_arg_free(char **str);
void	set_value(t_data *data);
void	map_oprt(t_data *data, char *arv);
void	rgb_storage(t_data *data, char *idf, char *rgb);
void	rgb_clr_code_err_msg(void);

char	*ft_strcpy(char *dst, const char *src);

#endif
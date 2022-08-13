/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:41:15 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/05/12 20:36:27 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

/*
xp: Horizontal location of player
yp: Vertial location of player
row_cnt: Line number of the map. Y axis on vertical
row_len: Line length of the map. X axis on vertical
*/

typedef struct sl_data
{
	int	ltr_idx;
	int	ltr_arg;
	int	p_cnt;
	int	c_cnt;
	int	e_cnt;
	int	wall_chk_arg;
	int	wal_chk_idx;
}	t_sdata;

typedef struct so_long
{
	t_sdata	ltr_check;
	void	*mlx;
	void	*win;
	void	**img_path;
	char	**map;
	char	**res;
	int		xp;
	int		yp;
	int		row_cnt;
	int		row_len;
	int		ttl_clc;
	int		score;
	int		step_cnt;
	int		nw_cnt;
	int		img_idx;
	int		img_arg;
}	t_data;

void	sub_zero(t_data *data);
void	images_create(t_data *data);
void	map_put_image(t_data *data);
void	map_read(t_data *data, char *str);
void	key_d(t_data *data);
void	key_a(t_data *data);
void	key_s(t_data *data);
void	key_w(t_data *data);
void	key_esc(t_data *data);
void	*ft_calloc(size_t nb, size_t n);
void	*ft_memset(void *s, int n, size_t nb);
void	map_newline_check(t_data *data);
void	map_rectangle_check(t_data *data);
void	map_ltr_check(t_data *data);
void	map_wall_check(t_data *data);
void	map_all_check(t_data *data);
int		map_name_check(char *str);
int		row_cnt(char *str);
int		ft_printf(const	char *s, ...);
int		type_srch(va_list vag, char c, int a);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		map_lenght(char *s);
int		find_key(int n, void *s);
int		clean_up(t_data *data);
char	*get_map(int n, char *str);
char	**ft_split(char const *str, char c, t_data *data);

#endif

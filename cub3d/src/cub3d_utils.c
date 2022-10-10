/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:54 by syildiri          #+#    #+#             */
/*   Updated: 2022/10/10 11:01:46 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cub3d.h"

void	set_value(t_data2 *data)
{
	data->pos_x = 12;
	data->pos_y = 5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->ground_x = 0;
	data->ground_y = 0.66;
	data->move_speed = 0.05;
	data->rot_speed = 0.05;
	data->ltr_arg = 0;
	data->ltr_idx = 0;
	data->n_cnt = 0;
	data->s_cnt = 0;
	data->e_cnt = 0;
	data->w_cnt = 0;
	data->wal_chk_arg = 0;
	data->wal_chk_idx = 0;
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			t;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str2)
	{
		t = 0;
		while (str1[t] != '\0' && str2[t] != '\0' && str1[t] == str2[t])
			t++;
		return (str1[t] - str2[t]);
	}
	return (1);
}

int	ft_arglen(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	ft_arg_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:44:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/18 11:05:59 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_value(t_data *data)
{
	data->pos_x = 12;
	data->pos_y = 5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->ground_x = 0;
	data->ground_y = 0.66;
	data->move_speed = 0.05;
	data->rot_speed = 0.05;
	data->nw_cnt = 1;
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
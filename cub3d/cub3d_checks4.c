/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:05:45 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/21 14:46:00 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	number_control(char *str)
{
	int i;
	int dgt_cnt;

	i = -1;
	while(str[++i])
	{
		if(ft_isdigit(str[i]) && str[i] != ',')
			dgt_cnt++;
		if(!ft_isdigit(str[i]) && str[i] != ',')
			return(0);
		if(dgt_cnt > 3)
			return (0);
		if(str[i] == ',')
			dgt_cnt = 0;
	}
	return(1);
}

static int	virgule_counter(char *str)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while(str[++i])
	{
		if(str[i] == ',')
			cnt++;
	}
	return(cnt);
}

void	map_ftrs_rgb_check(t_data *data, int i)
{
	char **str;
	while(data->map_ftrs[i])
	{
		str = ft_split(data->map_ftrs[i++], ' ');
		if(virgule_counter(str[1]) > 2)
		{
			write(2, "Error\nRGB Color Code is Wrong!", 30);
			exit(1);
		}
		if(number_control(str[1]) == 0)
		{
			write(2, "Error\nRGB Color Code is Wrong!", 30);
			exit(1);
		}
		else
		{
			printf("storage\n");
		}
	}
}
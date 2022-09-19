/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:28:07 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/19 14:42:29 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	idf_f_ctrl(t_data *data)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "F", 1) == 0)
			cnt++;
		if(cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			//free
			exit(1);
		}
	}	
}

void	idf_c_ctrl(t_data *data)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (data->map_ftrs[++i])
	{
		if (ft_strncmp(data->map_ftrs[i], "C", 1) == 0)
			cnt++;
		if(cnt > 1)
		{
			write(2, "Error\nSame identifer detected!", 30);
			//free
			exit(1);
		}
	}	
}

void	map_ftrs_element_check(t_data *data)
{
	char **str;
	int i;

	i = -1;
	while(data->map_ftrs[++i])
	{
		str = ft_split(data->map_ftrs[i], ' ');
		if(ft_arglen(str) != 2)
		{
			write(2, "Error\nToo Much Arguments!", 25);
			//free
			exit(1);			
		}
		ft_arg_free(str);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:05:45 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/27 13:41:35 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	rgb_nbr_empty_check(char *str)
{
	int i;
	
	i = -1;
	if(str[0] == ',')
	{
		write(2, "Error\nRGB Color Code is Empty!", 30);
		exit(1);
	}
	while(str[++i])
	{
		if((str[i] == ',' && str[i + 1] == ',') \
			|| (str[i] == ',' && str[i + 1] == 0))
		{
			write(2, "Error\nRGB Color Code is Empty!", 30);
			exit(1);
		}
	}
}

static void	rgb_value_check(t_data *data, char *idf)
{
	int i;

	i = -1;
	if(ft_strncmp(idf, "F", 1) == 0)
	{	
		while (++i < 3)
		{
			if(data->floor[i] > 255)
			{
				write(2, "Error\nColor Number Greater Than 255!", 36);
				exit(1);
			}
		}
	}
	else if(ft_strncmp(idf, "C", 1) == 0)
	{
		while (++i < 3)
		{
			if(data->ceil[i] > 255)
			{
				write(2, "Error\nColor Number Greater Than 255!", 36);
				exit(1);
			}
		}
	}
}

static void rgb_storage(t_data *data, char *idf, char *rgb)
{
	char **s;
	int i;
	
	i = -1;
	s = ft_split(rgb, ',');
	if(ft_strncmp(idf, "F", 1) == 0)
	{
		while (++i < 3)
			data->floor[i] = ft_atoi(s[i]);
	}
	else if(ft_strncmp(idf, "C", 1) == 0)
	{
		while (++i < 3)
			data->ceil[i] = ft_atoi(s[i]);
	}
	ft_arg_free(s);
}

static int	number_control(char *str)
{
	int i;
	int dgt_cnt;

	i = -1;
	dgt_cnt = 0;
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
		rgb_nbr_empty_check(str[1]);
		rgb_storage(data, str[0], str[1]);
		rgb_value_check(data, str[0]);
		ft_arg_free(str);	
	}
	data->floor_rgb = (data->floor[0] * 65536) + \
						(data->floor[1] * 256) + data->floor[2];
	data->ceil_rgb = (data->ceil[0] * 65536) + \
						(data->ceil[1] * 256) + data->ceil[2];
}
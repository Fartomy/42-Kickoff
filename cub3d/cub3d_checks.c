/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:32:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/19 13:41:58 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_format_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (*av == 0 || i-- < 5)
		return (0);
	if (av[i] == 'b' && av[i - 1] == 'u' && \
		av[i - 2] == 'c' && \
		av[i - 3] == '.')
		return (1);
	else
		return (0);
}

static void	map_ftrs_free(t_data *data, int i)
{
	int x;

	x = 0;
	while(x < i)
		free(data->map_ftrs[x++]);
}

static int identifer_check(char *str, int i)
{
		if (str[i] == 'N' && str[i + 1] == 'O')
			return (1);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (1);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (1);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (1);
		else if (str[i] == 'F')
			return (1);
		else if (str[i] == 'C')
			return (1);
		else
			return (0);
}

static int	identifer_ctrl(char *str)
{
	int	i;
	int x;
	int	cnt;

	i = -1;
	cnt = 0;
	while(str[++i])
	{
		while((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if(ft_isalpha(str[i]))
		{
			x = i;
			while(str[x] != ' ' && str[x])
			{
				cnt++;
				x++;
			}
			if(cnt > 2)
				return (0);
			else
				return(identifer_check(str, i));
		}
		else
			return(0);
	}
	return (0);
}

void	map_features_check(t_data *data)
{
	int i;
	char *str;

	i = -1;
	while (++i < 6)
	{
		if(identifer_ctrl(data->map_and_ftrs[i]) == 0)
		{
			write(2, "Error\nMap Features is Wrong!", 28);
			map_ftrs_free(data, i);
			exit(1);
		}
		if(identifer_ctrl(data->map_and_ftrs[i]) == 1)
		{
			str = ft_calloc(ft_strlen(data->map_and_ftrs[i]), sizeof(char) + 1);
			ft_strcpy(str, data->map_and_ftrs[i]);
			data->map_ftrs[i] = ft_strtrim(str, " ");
			free(str);
		}
	}
	map_ftrs_is_same_check(data);
}
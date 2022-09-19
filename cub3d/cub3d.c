/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:31:44 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/19 13:01:14 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int arc, char **arv)
{
	t_data	data;
	
	if(arc == 2 && map_format_check(arv[1]))
	{
		set_value(&data);
		map_oprt(&data, arv[1]);
		map_features_check(&data);
		map_ftrs_is_same_check(&data);
	}
	else
		write(2, "Error\nWrong Argument or Wrong Map Format!", 41);
}
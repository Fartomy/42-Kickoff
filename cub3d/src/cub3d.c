/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:31:44 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/22 20:01:21 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int arc, char **arv)
{
	t_data	data;
	
	if(arc == 2 && map_format_check(arv[1]))
	{
		set_value(&data);
		map_oprt(&data, arv[1]);
		map_features_check(&data);
		map_is_correct_check(&data);
		map_ltr_cnt(&data);
		map_all_check(&data);
	}
	else
		write(2, "Error\nWrong Argument or Wrong Map Format!", 41);
}

/*
row_len, row_cnt ve nw_cnt sadece haritanın değerleri değil, bütün .cub dosyasının row_len'i ve row_cnt'si ve nw_cnt'si!!!!!1
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:53:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/13 18:31:55 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(char **parse)
{
	int i;

	i = chdir(parse[1]);
	if(i == -1)
		printf("minishell: %s: %s: No such file or directory\n", parse[0], parse[1]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/17 16:20:27 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_export(char **parse)
{
    int i;

    i = 0;
    if(ft_strcmp(parse[i], "export") == 0 && !parse[i + 1])
    {
        while (data.export[i])
            printf("declare -x %s\n", data.env[i++]);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/16 18:02:13 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_export(char **parse)
{
    (void)parse;
    int i;

    i = 0;
    while (data.env[i])
        printf("declare -x %s\n", data.env[i++]);
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:21:08 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 16:47:44 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(char **parse)
{
    int i;

    i = 0;
    if(ft_strcmp(parse[i], "env") == 0 && !parse[i + 1])
    {
        while (data.env[i])
            printf("%s\n", data.env[i++]);
    }
    else if(ft_strcmp(parse[i], "env") == 0 && parse[i + 1])
    {
        data.status = 127;
        printf("%s: %s: No such file or directory\n", parse[i], parse[i + 1]);
    }
}
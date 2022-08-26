/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:46:47 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/26 16:23:53 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_pwd(char **parse)
{
    int i;

    i = 0;
    if(parse[i + 1])
        printf("pwd: too many arguments\n");
    else
    {
        char *pwd;

        pwd = getcwd(NULL, 0);
        printf("%s\n", pwd);
        free(pwd);
    }
}
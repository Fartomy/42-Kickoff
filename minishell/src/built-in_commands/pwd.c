/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:46:47 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 16:54:02 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_pwd(char **parse)
{
    (void)parse;
    char *pwd;

    pwd = getcwd(NULL, 0);
    printf("%s\n", pwd);
    free(pwd);
}

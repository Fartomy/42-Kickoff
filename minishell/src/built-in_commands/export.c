/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/19 12:20:24 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int expt_is_it_same_var(char *var)
{
    int i;
    int a;

    i = 0;
    while (var[i] != '=')
        i++;
    a = i;
    if(var[i] == '=')
    {
        bool is_it;

        is_it = false;
        i = -1;
        while (data.export[i])
        {
            if(ft_strncmp(data.env[i], var, i) == 0)
            {
                while (data.env[i][++a])
                {
                    if(data.env[i][a] != var[a])
                    {
                        data.env[i] = ft_realloc(var, ft_strlen(var));
                        return (0);
                    }
                }
                return (1); // değişken varsa ve değeride aynıysa
            }
            return (2); // değişken yoksa
        }
    }
    else
    {
        // '=' yoksa
    }
    
}

static void export_add_variable(char *var)
{
    int     i;
    bool    equal_ctrl;

    i = -1;
    equal_ctrl = false;
    while (var[++i])
    {
        if(var[i] == '=')
            equal_ctrl = true;
    }
    if(equal_ctrl == true)
    {
        printf("xd");
    }
    else
    {
        int a;

        a = 0;
        while (data.export[a])
            a++;
        data.export[a] = ft_strdup(var);
        data.export[a + 1] = 0;
        export_sorter(data.export);
    }
}

void    ft_export(char **parse)
{
    int i;

    i = 0;
    if(ft_strcmp(parse[i], "export") == 0 && !parse[i + 1])
    {
        while (data.export[i])
            printf("declare -x %s\n", data.export[i++]);
    }
    else if(ft_strcmp(parse[i], "export") == 0 && parse[i + 1])
    {
        i = 1;
        while (parse[i])
        {
            if(parse[i][0] == '_' && (parse[i][1] == 0 || parse[i][1] == '='))
                printf("");
            else if((parse[i][0] == '_' && parse[i][1] != 0) || ft_isalpha(parse[i][0]))
                export_add_variable(parse[i]);
            else
                printf("minishell: %s: `%c': not a valid identifier\n", parse[0], parse[i][0]);
            i++;
        }
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/21 02:25:15 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void export_add_variable(char *var)
{
    int i;
    char *tmp;
    char *env_name;
    
    i = -1;
    tmp = env_name_getter(var);
    while (data.export[++i])
    {
        env_name = env_name_getter(data.export[i]);
        if(ft_strcmp(env_name, tmp) == 0)
        {
            if(equal_finder(data.export[i]) == 1 && equal_finder(var) == 0)
            {
                free(env_name);
                free(tmp);
                return ;
            }
            else if(equal_finder(data.export[i]) == 0 && equal_finder(var) == 1)
            {
                int x;
                bool env_ctrl = false;
                
                x = -1;
                free(env_name);
                while (data.env[++x])
                {
                    env_name = env_name_getter(data.env[x]);
                    if(ft_strcmp(env_name, tmp) == 0)
                    {
                        free(env_name);
                        env_ctrl = true;
                        free(data.env[x]);
                        data.env[x] = ft_strdup(var);
                        break ;
                    }
                    free(env_name);
                }
                free(tmp);
                free(data.export[i]);
                data.export[i] = ft_strdup(var);
                if(env_ctrl == false)
                {
                    data.env = ft_rrealloc(data.env, ft_arglen(data.env) + 1);
                    data.env[x] = ft_strdup(var);
                    data.env[x + 1] = 0;
                }
                data.export = export_sorter(data.export);
                return ;
            }
            else if(equal_finder(data.export[i]) == 1 && equal_finder(var) == 1)
            {
                int x;
                bool env_ctrl = false;
                
                x = -1;
                free(env_name);
                while (data.env[++x])
                {
                    env_name = env_name_getter(data.env[x]);
                    if(ft_strcmp(env_name, tmp) == 0)
                    {
                        free(env_name);
                        free(data.env[x]);
                        env_ctrl = true;
                        data.env[x] = ft_strdup(var);
                        break ;
                    }
                    free(env_name);
                }
                free(tmp);
                free(data.export[i]);
                data.export[i] = ft_strdup(var);
                if(env_ctrl == false)
                {
                    data.env[x] = ft_strdup(var);
                    data.env[x + 1] = 0;
                }
                data.export = export_sorter(data.export);
                return ;
            }
            else
            {
                free(env_name);
                free(tmp);
                return ;
            }
        }
        free(env_name);
    }
    free(tmp);
    if(equal_finder(var) == 1)
    {
        data.export = ft_rrealloc(data.export, ft_arglen(data.export) + 1);
        data.export[i] = ft_strdup(var);
        data.export[i + 1] = 0;
        data.export = export_sorter(data.export);
        i = 0;
        while (data.env[i])
            i++;
        data.env = ft_rrealloc(data.env, ft_arglen(data.env) + 1);
        data.env[i] = ft_strdup(var);
        data.env[i + 1] = 0;
    }
    else 
    {
        data.export = ft_rrealloc(data.export, ft_arglen(data.export) + 1);
        data.export[i] = ft_strdup(var);
        data.export[i + 1] = 0;
        data.export = export_sorter(data.export);
    }
}

void    ft_export(char **parse)
{
    int i;

    i = 0;
    if(ft_strcmp(parse[i], "export") == 0 && !parse[i + 1])
    {
        while (data.export[i])
        {
            if(equal_finder(data.export[i]) == 1)
            {
                char *env_name;
                char *value;

                env_name = env_name_getter(data.export[i]);
                value = env_getter(data.export[i]);                
                printf("declare -x %s=\"%s\"\n", env_name, value);
                free(env_name);
                free(value);
            }
            else
                printf("declare -x %s\n", data.export[i]);
            i++;
        } 
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
                printf("minishell: %s: `%s': not a valid identifier\n", parse[0], parse[i]);
            i++;
        }
    }
}
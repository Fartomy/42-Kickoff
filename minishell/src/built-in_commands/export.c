/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/20 17:02:54 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int equal_finder(char *var)
{
    int i;

    i = -1;
    while (var[++i])
    {
        if(var[i] == '=')
            return(1);
    }
    return(0);
}

static char *env_name_getter(char *var)
{
    int i;
    char *name;
    
    i = 0;
    while (var[i] != '=' && var[i])
        i++;
    name = ft_calloc(sizeof(char), (i + 1));
    i = -1;
    while (var[++i] != '=' && var[i])
        name[i] = var[i];
    name[i] = 0;
    return(name);    
}

static void export_add_variable(char *var)
{
    int i;
    char *tmp;
    char *env_name;
    
    i = 0;
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

                x = -1;
                free(env_name);
                while (data.env[++x])
                {
                    env_name = env_name_getter(data.env[x]);
                    if(ft_strcmp(env_name, tmp) == 0)
                    {
                        free(env_name);
                        break ;
                    }
                    free(env_name);
                }
                free(tmp);
                free(data.export[i]);
                free(data.env[x]);
                data.env[x] = ft_strdup(var);
                data.export[i] = ft_strdup(var);
                //data.export = export_sorter(data.export);
                //data.export = export_quote_adder(data.export);
                return ;
            }
            else if(equal_finder(data.export[i]) == 1 && equal_finder(var) == 1)
            {
                int x;

                x = -1;
                free(env_name);
                while (data.env[++x])
                {
                    env_name = env_name_getter(data.env[x]);
                    if(ft_strcmp(env_name, tmp) == 0)
                    {
                        free(env_name);
                        break ;
                    }
                    free(env_name);
                }
                free(tmp);
                free(data.export[i]);
                free(data.env[x]);
                data.env[x] = ft_strdup(var);
                data.export[i] = ft_strdup(var);
                /* data.export = export_sorter(data.export);
                data.export = export_quote_adder(data.export); */
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
        data.export[i] = ft_strdup(var);
        data.export[i + 1] = 0;
/*         data.export = export_sorter(data.export);
        data.export = export_quote_adder(data.export); */
        i = 0;
        while (data.env[i])
            i++;
        data.env[i] = ft_strdup(var);
        data.env[i + 1] = 0;
    }
    else
    {
        data.export[i] = ft_strdup(var);
        data.export[i + 1] = 0;
/*         data.export = export_sorter(data.export);
        data.export = export_quote_adder(data.export); */
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
                printf("minishell: %s: `%s': not a valid identifier\n", parse[0], parse[i]);
            i++;
        }
    }
}
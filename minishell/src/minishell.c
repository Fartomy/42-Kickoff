/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:37:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/18 23:18:15 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minidata data;

char	**storage_and_copy(char **env)
{
	int i;
	int x;
	char **str;
	
	str = ft_calloc(sizeof(char *), ft_arglen(env) + 1);
	i = -1;
	while (env[++i])
		str[i] = ft_calloc(sizeof(char), ft_strlen(env[i]) + 1);
	i = -1;
	while (env[++i])
	{
		x = -1;
		while (env[i][++x])
			str[i][x] = env[i][x];
	}
	return (str);
}

static	char	*exprt_quo_add_helper(char **expt, int *i, int *x)
{
	int a;
	char *str;
    char *str1;
    char *str2;
    
    a = 0;
    str1 = malloc(sizeof(char) * (*x + 2));
    *x = -1;
    while(expt[*i][++(*x)] != '=')
      str1[*x] = expt[*i][*x];
    str1[(*x)++] = '=';
    str1[*x] = 0;
    while(expt[*i][(*x)++])
      a++;
    str2 = malloc(sizeof(char) * a + 3);
    str2[0] = 34;
    *x -= (a + 1);
    a = 1;
    while(expt[*i][*x])
      str2[a++] = expt[*i][(*x)++];
    str2[a++] = 34;
    str2[a] = 0;
    str = ft_strjoin(str1, str2);
    free(str1);
    free(str2);
	return (str);
} 

char    **export_quote_adder(char **export_envs)
{
    int i;
    int x;
	int a;

    i = -1;
    while (export_envs[++i])
    {
        x = 0;
        while (export_envs[i][x] != '=')
            x++;
		a = x;
		while (export_envs[i][x])
			x++;
    	if(export_envs[i][a] == '=' && export_envs[i][a + 1] != 34 && export_envs[i][x - 1] != 34)
			export_envs[i] = exprt_quo_add_helper(export_envs, &i, &x);
    }
	return(export_envs);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	data.env = storage_and_copy(envp);
	data.export = storage_and_copy(envp);
	data.export = export_sorter(data.export);
	data.export = export_quote_adder(data.export);
	set_symbol_token(data.symbol_tkn);
	set_builtin_token(data.built_in_tkn);
	prompt();
}
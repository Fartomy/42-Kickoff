/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:37:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/17 16:18:53 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minidata data;

char**	export_sorter(char **envp)
{
	int i;
	char *tmp;
	
	i = 0;
	while (envp[i])
	{
		if(envp[i + 1] && (envp[i][0] > envp[i + 1][0]))
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = -1;	
		}
		i++;
	}
	return (envp);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	data.env = envp;
	data.export = export_sorter(envp);
	set_symbol_token(data.symbol_tkn);
	set_builtin_token(data.built_in_tkn);
	prompt();
}
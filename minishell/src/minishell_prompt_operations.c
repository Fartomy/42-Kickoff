/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:27:01 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/24 17:13:10 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_command(char **parse)
{
	if(ft_strcmp(parse[0], data.built_in_tkn[0]) == 0)
		ft_echo(parse);
 	else if(ft_strcmp(parse[0], data.built_in_tkn[1]) == 0)
		ft_cd(parse);
	else if(ft_strcmp(parse[0], data.built_in_tkn[2]) == 0)
		ft_pwd();
	else if(ft_strcmp(parse[0], data.built_in_tkn[3]) == 0)
		ft_export(parse);
	else if(ft_strcmp(parse[0], data.built_in_tkn[5]) == 0)
		ft_env(parse);
	else if(ft_strcmp(parse[0], data.built_in_tkn[4]) == 0)
		ft_unset(parse);
	else if(ft_strcmp(parse[0], data.built_in_tkn[6]) == 0)
		ft_exit(parse);
}

void	builtin_or_smp_cmd_ctrl(char **parse)
{
	int 	i;
	int 	x;
	bool	builtin_ctrl;
	
	i = -1;
	builtin_ctrl = false;
	parse = ft_implt_split(parse[0], ' ');
	parse = quotes_purifyer(parse);
	i = 0;
	while(parse[i])
	{
		x = 0;
		while (ft_strcmp(parse[i], data.built_in_tkn[x]) != 0 && data.built_in_tkn[x])
			x++;
		if(ft_strcmp(parse[i], data.built_in_tkn[x]) == 0)
		{
			builtin_ctrl = true;
			builtin_command(parse);
			break ;
		}
		i++;
	}
	if(builtin_ctrl == false)
		cmd_finder(parse);
	ft_free(parse);
}

void	simple_cmd(char **parse)
{
	bool	symbol_ctrl;
	int 	i;
	int		x;

	// redirections command control ↓
	i = 0;
	symbol_ctrl = false;
	parse = ft_symbol_split(parse[0]); // FREEEEEEEEEEEEEEEEEEEEEEEEEEE
	while (parse[i])
	{
		x = 0;
		while (ft_strcmp(parse[i], data.symbol_tkn[x]) != 0 && data.symbol_tkn[x])
			x++;
		if(ft_strcmp(parse[i], data.symbol_tkn[x]) == 0)
		{
			symbol_ctrl = true;
			//func
			break;
		}
		i++;
	}
	if(symbol_ctrl == false)
		builtin_or_smp_cmd_ctrl(parse);
	ft_free(parse);
}

void	cmd_router(char **parse)
{
	int i;
	bool simple_cmd_ctrl;

	i = 0;
	simple_cmd_ctrl = false;
	while (parse[i])
	{
		if(ft_strcmp(parse[i], "|") == 0)
		{
			simple_cmd_ctrl = true;
			//piped_cmd(parse);
			break ;
		}
		i++;
	}
	if(simple_cmd_ctrl == false)
		simple_cmd(parse);
}
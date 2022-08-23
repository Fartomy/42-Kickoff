/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:06:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/23 15:21:24 by ftekdrmi         ###   ########.fr       */
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
	while (parse[++i])
		parse[i] = env_converter(parse[i]);
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
	// built-in or simple command control ↓
	if(symbol_ctrl == false)
		builtin_or_smp_cmd_ctrl(parse);
	ft_free(parse);
	//pause();
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

static char *get_username(void)
{
	char *str;
	char *usr_env;
	char *prompt;
	int i;
	
	i = 0;
	prompt = ft_calloc(sizeof(char), 30);
	str = "\033[0;32mminishell@ >_ ";
	usr_env = getenv("USER");
	while (*str)
	{
		prompt[i++] = *str;
		if(*str == '@')
		{
			while (*usr_env)
				prompt[i++] = *usr_env++;
		}
		str++;			
	}
	return (prompt);
}

int		cmd_space_ctrl(char *cmd)
{
	while (*cmd)
	{
		if(*cmd != ' ')
			return (0);
		cmd++;
	}
	return(1);
	
}

void	prompt(void)
{
	char **prs;
	char *cmd;
	char *usr_name;
		
    while(1)
	{
		usr_name = get_username(); //FREEEEEEEEEEEEEEEEEEE (OK)
		cmd = readline(usr_name); // FREEEEEEEEEEEEEEEEEEE (OK)
		if((unsigned char)*cmd >= 32 && (unsigned char)*cmd < 255 && !cmd_space_ctrl(cmd))
		{
			add_history(cmd);
			prs = ft_pipe_split(cmd, '|'); //FREEEEEEEEEEEEEEEEEEE (OK)
			cmd_router(prs);
			ft_free(prs);
		}
		if (cmd)
			free(cmd);
		if (usr_name)
			free(usr_name); 
	}
}

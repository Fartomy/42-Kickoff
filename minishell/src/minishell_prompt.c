/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:06:38 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/24 16:01:48 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *get_username(void)
{
	char *str;
	char *usr_env;
	char *prompt;
	int i;
	
	i = 0;
	prompt = ft_calloc(sizeof(char), 50);
	str = "[minishell@] >_ ";
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

void	prompt(void)
{
	char **parse;
	char *cmd;
	char *usr_name;
		
    while(1)
	{
		usr_name = get_username(); //FREEEEEEEEEEEEEEEEEEE (OK)
		cmd = readline(usr_name); // FREEEEEEEEEEEEEEEEEEE (OK)
		if (!cmd)
			exit(0);
		if((unsigned char)*cmd >= 32 && (unsigned char)*cmd < 255 && !cmd_space_ctrl(cmd))
		{
			add_history(cmd);
			parse = ft_pipe_split(cmd, '|'); //FREEEEEEEEEEEEEEEEEEE (OK)
			cmd_router(parse);
			ft_free(parse);
		}
		if (cmd)
			free(cmd);
		if (usr_name)
			free(usr_name);
	}
}

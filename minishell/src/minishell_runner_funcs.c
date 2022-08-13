/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_runner_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:01:49 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/13 14:02:40 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**env_add_slash(char **paths)
{
	int i;
	int len;
	
	i = 0;
	while(paths[i])
	{
		len = ft_strlen(paths[i]);
		paths[i][len] = '/';
		paths[i][len + 1] = 0;
		i++;
	}
	return (paths);
}

static char	**path_sptr(void)
{
	int i;
	char *env_path = NULL;
	char **paths;

	i = 0;
	while(data.env[i])
	{
		if(ft_strncmp(data.env[i], "PATH", 4) == 0)
		{
			env_path = data.env[i];
			break ;
		}
		i++;
	}
	i = -1;
	while(env_path[++i] != '='){}
	env_path += i + 1;
	paths = ft_split(env_path, ':'); 
	paths = env_add_slash(paths);
	return (paths);
}

static	void cmd_runner(char *path, char **opt)
{
	pid_t pid;

	pid = fork();
	if(pid > 0)
		wait(NULL);
	if(pid == 0)
	{
		if(execve(path, opt, NULL) == -1)
			exit(0);
		exit(0);
	}
	free(opt);
}

void	cmd_finder(char **parse)
{
	char **paths;
	char **opt;
	char *join;
	int i;
	int x;
	bool ctrl;
	
	parse = quotes_purifyer(parse);
	ctrl = false;
	paths = path_sptr(); //freeeeeeeeee
	opt = ft_calloc(sizeof(char *), 40); //freeeeeeeee
	i = -1;
	while(paths[++i])
	{
		join = ft_strjoin(paths[i], parse[0]); //freeeeeeee
		if(access(join, F_OK) == 0)
		{
			ctrl = true;
			x = -1;
			while(parse[++x])
				opt[x] = parse[x];
			opt[x] = 0;
			cmd_runner(join, opt);
			break ;
		}
		else if(access(parse[0], F_OK) == 0)
		{
			ctrl = true;
			x = -1;
			while(parse[++x])
				opt[x] = parse[x];
			opt[x] = 0;
			cmd_runner(parse[0], opt);
			break ;
		}
	}
	if(ctrl == false)
		printf("minishell: %s: command not found\n", parse[0]);
	ft_free(paths);
	free(join);
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_runner_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:01:49 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/25 20:28:52 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **env_add_slash(char **paths)
{
	int i;
	int len;

	i = 0;
	while (paths[i])
	{
		len = ft_strlen(paths[i]);
		paths[i][len] = '/';
		paths[i][len + 1] = 0;
		i++;
	}
	return (paths);
}

static char **path_sptr(void)
{
	int i;
	char *env_path;
	char **paths;

	env_path = NULL;
	i = -1;
	while (data.env[++i])
	{
		if (ft_strncmp(data.env[i], "PATH", 4) == 0)
		{
			env_path = data.env[i];
			break ;
		}
	}
	i = 0;
	if (env_path == NULL)
		return (NULL);
	while (env_path[i] != '=')
		i++;
	env_path += i + 1;
	paths = ft_split(env_path, ':');
	paths = env_add_slash(paths);
	return (paths);
}

static void cmd_runner(char *path, char **opt)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		if (execve(path, opt, NULL) == -1)
			exit(0);
		exit(0);
	}
}

void	cmd_finder(char **parse)
{
	char **paths;
	char **opt;
	char *join;
	int i;
	int x;
	bool ctrl;

	ctrl = false;
	paths = path_sptr(); // freeeeeeee (OK)
	opt = ft_calloc(sizeof(char *), 42); // freeeeeeeee
	if (!paths)
	{
		if (access(parse[0], F_OK) == 0)
		{
			ctrl = true;
			x = -1;
			while (parse[++x])
			{
				opt[x] = ft_calloc(sizeof(char *), 42);
				opt[x] = ft_strcpy(opt[x], parse[x]);
			}
			cmd_runner(parse[0], opt);
			ft_free(opt);
		}
		else
		{
			free(opt);
			printf("minishell: %s: command not found\n", parse[0]);
		}
		return ;
	}
	i = -1;
	if (ft_strncmp(parse[0], "./", 2))
	{
		while (paths[++i])
		{
			join = ft_strjoin(paths[i], parse[0]); // freeeeeee
			if (access(join, F_OK) == 0)
			{
				ctrl = true;
				x = -1;
				while (parse[++x])
				{
					opt[x] = ft_calloc(sizeof(char *), 42);
					opt[x] = ft_strcpy(opt[x], parse[x]);
				}
				cmd_runner(join, opt);
				free(join);
				break;
			}
			else if (access(parse[0], F_OK) == 0)
			{
				ctrl = true;
				x = -1;
				while (parse[++x])
				{
					opt[x] = ft_calloc(sizeof(char *), 42);
					opt[x] = ft_strcpy(opt[x], parse[x]);
				}
				cmd_runner(parse[0], opt);
				free(join);
				break;
			}
			free(join);
		}
	}
	if (ctrl == false)
		printf("minishell: %s: command not found\n", parse[0]);
	ft_free(paths);
	ft_free(parse);
	if (opt)
		ft_free(opt);
}
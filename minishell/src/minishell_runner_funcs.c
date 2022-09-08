/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_runner_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:01:49 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**env_add_slash(char **paths)
{
	int	i;
	int	len;

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

static char	**path_sptr(void)
{
	int		i;
	char	*env_path;
	char	**paths;

	env_path = NULL;
	i = -1;
	while (g_dt.env[++i])
	{
		if (ft_strncmp(g_dt.env[i], "PATH", 4) == 0)
		{
			env_path = g_dt.env[i];
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

void	cmd_runner(char *path, char **opt)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &g_dt.status, 0);
		g_dt.status %= 255;
	}
	if (pid == 0)
	{
		if (execve(path, opt, g_dt.env) == -1)
			exit(0);
		exit(0);
	}
}

void	cmd_finder(char **parse)
{
	t_cmd_finder_vars	cmf;

	cmf.i = -1;
	cmf.ctrl = false;
	cmf.paths = path_sptr();
	cmf.opt = ft_calloc(sizeof(char *), 42);
	if (cmd_fdr_ifnot_path(&cmf, parse))
		return ;
	cmd_fdr_if_path(&cmf, parse);
	if (cmf.ctrl == false)
	{
		g_dt.status = 127;
		printf("minishell: %s: command not found\n", parse[0]);
	}
	ft_free(cmf.paths);
	ft_free(parse);
	if (cmf.opt)
		ft_free(cmf.opt);
}

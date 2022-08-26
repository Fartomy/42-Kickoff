/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:53:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/26 16:41:00 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void update_pwd(void)
{
	int i;
	char *pwd;
	char *bufpwd;
	
	i = -1;
	pwd = "PWD=";
	while (data.env[++i])
	{
		if (ft_strncmp(data.env[i], "PWD", 3) == 0)
		{
			free(data.env[i]);
			bufpwd = getcwd(NULL, 0);
			data.env[i] = ft_strjoin(pwd, bufpwd);
			free(bufpwd);
			break ;
		}
	}
	i = -1;
	while (data.export[++i])
	{
		if(ft_strncmp(data.export[i], "PWD", 3) == 0)
		{
			free(data.export[i]);
			bufpwd = getcwd(NULL, 0);
			data.export[i] = ft_strjoin(pwd, bufpwd);
			free(bufpwd);
			break ;
		}
	}
}

static void	update_old_pwd(void)
{
	int i;
	char *oldpwd;
	char *bufpwd;

	oldpwd = "OLDPWD=";
	i = -1;
	while (data.env[++i])
	{
		if(ft_strncmp(data.env[i], "OLDPWD", 6) == 0)
		{
			free(data.env[i]);
			bufpwd = getcwd(NULL, 0);
			data.env[i] = ft_strjoin(oldpwd, bufpwd);
			free(bufpwd);
			break ;
		}	
	}
	i = -1;
	while (data.export[++i])
	{
		if (ft_strncmp(data.export[i], "OLDPWD", 6) == 0)
		{
			free(data.export[i]);
			bufpwd = getcwd(NULL, 0);
			data.export[i] = ft_strjoin(oldpwd, bufpwd);
			free(bufpwd);
			break ;
		}
	}
}

void    ft_cd(char **parse)
{
	if(!parse[1])
	{
		int i;

		i = 0;
		while (data.env[i])
		{
			if(ft_strncmp(data.env[i], "HOME", 4) == 0)
			{
				char *home_value;
				
				home_value = env_getter(data.env[i]);
				update_old_pwd();
				chdir(home_value);
				update_pwd();
				free(home_value);
			}
			i++;
		}
	}
	else if(ft_strcmp(parse[1], "-") == 0)
	{
		int i;

		i = 0;
		while (data.env[i])
		{
			if(ft_strncmp(data.env[i], "OLDPWD", 6) == 0)
			{
				char *oldpwd_value;

				oldpwd_value = env_getter(data.env[i]);
				chdir(oldpwd_value);
				update_pwd();
				printf("%s\n", oldpwd_value);
				free(oldpwd_value);
			}
			i++;
		}
	}
	else
	{
		update_old_pwd();
		if(chdir(parse[1]) == -1)
			printf("minishell: %s: %s: No such file or directory\n", parse[0], parse[1]);
		else
			update_pwd();
	}
}
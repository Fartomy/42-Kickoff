/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_help_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:59:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 04:01:13 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	uptd_old_pwd_env(void)
{
	int		i;
	char	*oldpwd;
	char	*bufpwd;

	i = -1;
	oldpwd = "OLDPWD=";
	while (data.env[++i])
	{
		if (ft_strncmp(data.env[i], "OLDPWD", 6) == 0)
		{
			free(data.env[i]);
			bufpwd = getcwd(NULL, 0);
			data.env[i] = ft_strjoin(oldpwd, bufpwd);
			free(bufpwd);
			break ;
		}	
	}
}

void	uptd_old_pwd_export(void)
{
	int		i;
	char	*oldpwd;
	char	*bufpwd;

	i = -1;
	oldpwd = "OLDPWD=";
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

void	uptd_pwd_env(void)
{
	int		i;
	char	*pwd;
	char	*bufpwd;

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
}

void	uptd_pwd_export(void)
{
	int		i;
	char	*pwd;
	char	*bufpwd;

	i = -1;
	pwd = "PWD=";
	while (data.export[++i])
	{
		if (ft_strncmp(data.export[i], "PWD", 3) == 0)
		{
			free(data.export[i]);
			bufpwd = getcwd(NULL, 0);
			data.export[i] = ft_strjoin(pwd, bufpwd);
			free(bufpwd);
			break ;
		}
	}
}

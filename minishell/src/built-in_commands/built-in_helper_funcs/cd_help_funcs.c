/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_help_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:59:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
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
	while (g_dt.env[++i])
	{
		if (ft_strncmp(g_dt.env[i], "OLDPWD", 6) == 0)
		{
			free(g_dt.env[i]);
			bufpwd = getcwd(NULL, 0);
			g_dt.env[i] = ft_strjoin(oldpwd, bufpwd);
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
	while (g_dt.export[++i])
	{
		if (ft_strncmp(g_dt.export[i], "OLDPWD", 6) == 0)
		{
			free(g_dt.export[i]);
			bufpwd = getcwd(NULL, 0);
			g_dt.export[i] = ft_strjoin(oldpwd, bufpwd);
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
	while (g_dt.env[++i])
	{
		if (ft_strncmp(g_dt.env[i], "PWD", 3) == 0)
		{
			free(g_dt.env[i]);
			bufpwd = getcwd(NULL, 0);
			g_dt.env[i] = ft_strjoin(pwd, bufpwd);
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
	while (g_dt.export[++i])
	{
		if (ft_strncmp(g_dt.export[i], "PWD", 3) == 0)
		{
			free(g_dt.export[i]);
			bufpwd = getcwd(NULL, 0);
			g_dt.export[i] = ft_strjoin(pwd, bufpwd);
			free(bufpwd);
			break ;
		}
	}
}

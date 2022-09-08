/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:53:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(void)
{
	uptd_pwd_env();
	uptd_pwd_export();
}

static void	update_old_pwd(void)
{
	uptd_old_pwd_env();
	uptd_old_pwd_export();
}

static void	ft_cd_home(void)
{
	int		i;
	char	*home_value;

	i = 0;
	while (g_dt.env[i])
	{
		if (ft_strncmp(g_dt.env[i], "HOME", 4) == 0)
		{
			home_value = env_getter(g_dt.env[i]);
			update_old_pwd();
			chdir(home_value);
			update_pwd();
			free(home_value);
		}
		i++;
	}
	g_dt.status = 0;
}

static void	ft_cd_oldpwd(void)
{
	int		i;
	char	*oldpwd_value;

	i = 0;
	while (g_dt.env[i])
	{
		if (ft_strncmp(g_dt.env[i], "OLDPWD", 6) == 0)
		{
			oldpwd_value = env_getter(g_dt.env[i]);
			chdir(oldpwd_value);
			update_pwd();
			printf("%s\n", oldpwd_value);
			free(oldpwd_value);
		}
		i++;
	}
	g_dt.status = 0;
}

void	ft_cd(char **parse)
{
	if (!parse[1])
		ft_cd_home();
	else if (ft_strcmp(parse[1], "-") == 0)
		ft_cd_oldpwd();
	else
	{
		update_old_pwd();
		if (chdir(parse[1]) == -1)
		{
			g_dt.status = 1;
			printf("minishell: %s: %s: No such file or directory\n", \
					parse[0], parse[1]);
		}
		else
			update_pwd();
		g_dt.status = 0;
	}
}

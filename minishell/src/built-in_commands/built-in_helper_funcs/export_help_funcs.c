/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:20:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exprt_addvar_mini_help(t_export_vars *exp, int *env_ctrl, \
									int *x, char *var)
{
	while (g_dt.env[++(*x)])
	{
		exp->env_name = env_name_getter(g_dt.env[*x]);
		if (ft_strcmp(exp->env_name, exp->tmp) == 0)
		{
			free(exp->env_name);
			free(g_dt.env[*x]);
			*env_ctrl = 1;
			g_dt.env[*x] = ft_strdup(var);
			break ;
		}
		free(exp->env_name);
	}
}

int	export_add_var_helper(t_export_vars *exp, char *var)
{
	int		x;
	int		env_ctrl;

	env_ctrl = 0;
	x = -1;
	free(exp->env_name);
	exprt_addvar_mini_help(exp, &env_ctrl, &x, var);
	free(exp->tmp);
	free(g_dt.export[exp->i]);
	g_dt.export[exp->i] = ft_strdup(var);
	if (env_ctrl == 0)
	{
		g_dt.env = ft_rrealloc(g_dt.env, ft_arglen(g_dt.env) + 1);
		g_dt.env[x] = ft_strdup(var);
		g_dt.env[x + 1] = 0;
	}
	g_dt.export = export_sorter(g_dt.export);
	return (1);
}

int	export_add_var_helper2(t_export_vars *exp, char *var)
{
	int	x;
	int	env_ctrl;

	env_ctrl = 0;
	x = -1;
	free(exp->env_name);
	exprt_addvar_mini_help(exp, &env_ctrl, &x, var);
	free(exp->tmp);
	free(g_dt.export[exp->i]);
	g_dt.export[exp->i] = ft_strdup(var);
	if (env_ctrl == 0)
	{
		g_dt.env[x] = ft_strdup(var);
		g_dt.env[x + 1] = 0;
	}
	g_dt.export = export_sorter(g_dt.export);
	return (1);
}

int	export_add_var_body_helper(t_export_vars *exp, char *var)
{
	if (equal_finder(g_dt.export[exp->i]) == 1 && equal_finder(var) == 0)
	{
		free(exp->env_name);
		free(exp->tmp);
		return (1);
	}
	else if (equal_finder(g_dt.export[exp->i]) == 0 \
			&& equal_finder(var) == 1)
	{
		if (export_add_var_helper(exp, var))
			return (1);
	}
	else if (equal_finder(g_dt.export[exp->i]) == 1 \
			&& equal_finder(var) == 1)
	{
		if (export_add_var_helper2(exp, var))
			return (1);
	}
	else
	{
		free(exp->env_name);
		free(exp->tmp);
		return (1);
	}
	return (0);
}

void	export_add_var_equal(t_export_vars *exp, char *var)
{
	g_dt.export = ft_rrealloc(g_dt.export, ft_arglen(g_dt.export) + 1);
	g_dt.export[exp->i] = ft_strdup(var);
	g_dt.export[exp->i + 1] = 0;
	g_dt.export = export_sorter(g_dt.export);
	exp->i = 0;
	while (g_dt.env[exp->i])
		exp->i++;
	g_dt.env = ft_rrealloc(g_dt.env, ft_arglen(g_dt.env) + 1);
	g_dt.env[exp->i] = ft_strdup(var);
	g_dt.env[exp->i + 1] = 0;
}

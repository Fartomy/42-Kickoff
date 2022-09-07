/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:20:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 12:23:26 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exprt_addvar_mini_help(t_export_vars *exp, int *env_ctrl, \
									int *x, char *var)
{
	while (data.env[++(*x)])
	{
		exp->env_name = env_name_getter(data.env[*x]);
		if (ft_strcmp(exp->env_name, exp->tmp) == 0)
		{
			free(exp->env_name);
			free(data.env[*x]);
			*env_ctrl = 1;
			data.env[*x] = ft_strdup(var);
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
	free(data.export[exp->i]);
	data.export[exp->i] = ft_strdup(var);
	if (env_ctrl == 0)
	{
		data.env = ft_rrealloc(data.env, ft_arglen(data.env) + 1);
		data.env[x] = ft_strdup(var);
		data.env[x + 1] = 0;
	}
	data.export = export_sorter(data.export);
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
	free(data.export[exp->i]);
	data.export[exp->i] = ft_strdup(var);
	if (env_ctrl == 0)
	{
		data.env[x] = ft_strdup(var);
		data.env[x + 1] = 0;
	}
	data.export = export_sorter(data.export);
	return (1);
}

int	export_add_var_body_helper(t_export_vars *exp, char *var)
{
	if (equal_finder(data.export[exp->i]) == 1 && equal_finder(var) == 0)
	{
		free(exp->env_name);
		free(exp->tmp);
		return (1);
	}
	else if (equal_finder(data.export[exp->i]) == 0 \
			&& equal_finder(var) == 1)
	{
		if (export_add_var_helper(exp, var))
			return (1);
	}
	else if (equal_finder(data.export[exp->i]) == 1 \
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
	data.export = ft_rrealloc(data.export, ft_arglen(data.export) + 1);
	data.export[exp->i] = ft_strdup(var);
	data.export[exp->i + 1] = 0;
	data.export = export_sorter(data.export);
	exp->i = 0;
	while (data.env[exp->i])
		exp->i++;
	data.env = ft_rrealloc(data.env, ft_arglen(data.env) + 1);
	data.env[exp->i] = ft_strdup(var);
	data.env[exp->i + 1] = 0;
}

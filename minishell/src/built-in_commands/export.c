/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_add_var_body(t_export_vars *exp, char *var)
{
	exp->env_name = env_name_getter(g_dt.export[exp->i]);
	if (ft_strcmp(exp->env_name, exp->tmp) == 0)
	{
		if (export_add_var_body_helper(exp, var))
			return (1);
	}
	free(exp->env_name);
	return (0);
}

static void	export_add_variable(char *var)
{
	t_export_vars	exp;

	exp.i = -1;
	exp.tmp = env_name_getter(var);
	while (g_dt.export[++exp.i])
	{
		if (export_add_var_body(&exp, var))
			return ;
	}
	free(exp.tmp);
	if (equal_finder(var) == 1)
		export_add_var_equal(&exp, var);
	else
	{
		g_dt.export = ft_rrealloc(g_dt.export, ft_arglen(g_dt.export) + 1);
		g_dt.export[exp.i] = ft_strdup(var);
		g_dt.export[exp.i + 1] = 0;
		g_dt.export = export_sorter(g_dt.export);
	}
}

static void	export_display(int i)
{
	char	*env_name;
	char	*value;

	env_name = env_name_getter(g_dt.export[i]);
	value = env_getter(g_dt.export[i]);
	printf("declare -x %s=\"%s\"\n", env_name, value);
	free(env_name);
	free(value);
}

static void	export_ctrl_and_add_var(char **parse)
{
	int	i;

	i = 1;
	while (parse[i])
	{
		if (parse[i][0] == '_' && (parse[i][1] == 0 || parse[i][1] == '='))
			printf("");
		else if ((parse[i][0] == '_' && parse[i][1] != 0) || \
				ft_isalpha(parse[i][0]))
			export_add_variable(parse[i]);
		else
		{
			g_dt.status = 1;
			printf("minishell: %s: `%s': not a valid identifier\n", \
					parse[0], parse[i]);
		}
		i++;
	}
	g_dt.status = 0;
}

void	ft_export(char **parse)
{
	int	i;

	i = 0;
	if (ft_strcmp(parse[i], "export") == 0 && !parse[i + 1])
	{
		while (g_dt.export[i])
		{
			if (equal_finder(g_dt.export[i]) == 1)
				export_display(i);
			else
				printf("declare -x %s\n", g_dt.export[i]);
			i++;
		}
		g_dt.status = 0;
	}
	else if (ft_strcmp(parse[i], "export") == 0 && parse[i + 1])
		export_ctrl_and_add_var(parse);
}

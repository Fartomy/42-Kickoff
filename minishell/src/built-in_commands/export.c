/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:37:12 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 12:24:34 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_add_var_body(t_export_vars *exp, char *var)
{
	exp->env_name = env_name_getter(data.export[exp->i]);
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
	while (data.export[++exp.i])
	{
		if (export_add_var_body(&exp, var))
			return ;
	}
	free(exp.tmp);
	if (equal_finder(var) == 1)
		export_add_var_equal(&exp, var);
	else
	{
		data.export = ft_rrealloc(data.export, ft_arglen(data.export) + 1);
		data.export[exp.i] = ft_strdup(var);
		data.export[exp.i + 1] = 0;
		data.export = export_sorter(data.export);
	}
}

static void	export_display(int i)
{
	char	*env_name;
	char	*value;

	env_name = env_name_getter(data.export[i]);
	value = env_getter(data.export[i]);
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
			data.status = 1;
			printf("minishell: %s: `%s': not a valid identifier\n", \
					parse[0], parse[i]);
		}
		i++;
	}
	data.status = 0;
}

void	ft_export(char **parse)
{
	int	i;

	i = 0;
	if (ft_strcmp(parse[i], "export") == 0 && !parse[i + 1])
	{
		while (data.export[i])
		{
			if (equal_finder(data.export[i]) == 1)
				export_display(i);
			else
				printf("declare -x %s\n", data.export[i]);
			i++;
		}
		data.status = 0;
	}
	else if (ft_strcmp(parse[i], "export") == 0 && parse[i + 1])
		export_ctrl_and_add_var(parse);
}

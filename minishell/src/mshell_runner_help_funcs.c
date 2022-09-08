/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_runner_help_funcs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:58:59 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_fdr_ifnot_path(t_cmd_finder_vars *cmf, char **parse)
{
	if (!cmf->paths)
	{
		if (access(parse[0], F_OK) == 0)
		{
			cmf->ctrl = true;
			cmf->x = -1;
			while (parse[++cmf->x])
			{
				cmf->opt[cmf->x] = ft_calloc(sizeof(char *), 42);
				cmf->opt[cmf->x] = ft_strcpy(cmf->opt[cmf->x], parse[cmf->x]);
			}
			cmd_runner(parse[0], cmf->opt);
			ft_free(parse);
			ft_free(cmf->opt);
		}
		else
		{
			free(cmf->opt);
			g_dt.status = 127;
			printf("minishell: %s: command not found\n", parse[0]);
			ft_free(parse);
		}
		return (1);
	}
	return (0);
}

int	cmd_fdr_ifpt_helper(t_cmd_finder_vars *cmf, char **parse)
{
	cmf->ctrl = true;
	cmf->x = -1;
	while (parse[++cmf->x])
	{
		cmf->opt[cmf->x] = ft_calloc(sizeof(char *), 42);
		cmf->opt[cmf->x] = ft_strcpy(cmf->opt[cmf->x], \
							parse[cmf->x]);
	}
	cmd_runner(cmf->join, cmf->opt);
	free(cmf->join);
	return (1);
}

int	cmd_fdr_ifpt_helper2(t_cmd_finder_vars *cmf, char **parse)
{
	cmf->ctrl = true;
	cmf->x = -1;
	while (parse[++cmf->x])
	{
		cmf->opt[cmf->x] = ft_calloc(sizeof(char *), 42);
		cmf->opt[cmf->x] = ft_strcpy(cmf->opt[cmf->x], \
							parse[cmf->x]);
	}
	cmd_runner(parse[0], cmf->opt);
	free(cmf->join);
	return (1);
}

void	cmd_fdr_if_path(t_cmd_finder_vars *cmf, char **parse)
{
	if (ft_strncmp(parse[0], "./", 2))
	{
		while (cmf->paths[++cmf->i])
		{
			cmf->join = ft_strjoin(cmf->paths[cmf->i], parse[0]);
			if (access(cmf->join, F_OK) == 0)
			{
				if (cmd_fdr_ifpt_helper(cmf, parse))
					break ;
			}
			else if (access(parse[0], F_OK) == 0)
			{
				if (cmd_fdr_ifpt_helper2(cmf, parse))
					break ;
			}
			free(cmf->join);
		}
	}
}

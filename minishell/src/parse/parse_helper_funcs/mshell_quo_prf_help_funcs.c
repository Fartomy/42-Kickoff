/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_quo_prf_help_funcs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:47:03 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	status_oprt(char **env_var, int *b, int *ctrl, t_quo_prfy_vars *pf)
{
	char	*str;

	*ctrl = 1;
	str = ft_itoa(g_dt.status);
	while (str[*b])
	{
		(*env_var)[*b] = str[*b];
		(*b)++;
	}
	free(str);
	pf->i2 += 2;
}

void	quo_prf_helper(char **parse, t_quo_prfy_vars *pf)
{
	while (parse[pf->i][pf->i2])
	{
		if (parse[pf->i][pf->i2] != 34 && parse[pf->i][pf->i2] != '$')
			pf->prs[pf->x][pf->x2++] = parse[pf->i][pf->i2++];
		else if (parse[pf->i][pf->i2] != 34 && parse[pf->i][pf->i2] == '$')
			quo_transformer(parse, pf);
		else
			pf->i2++;
	}
}

void	quo_prf_helper2(char **parse, t_quo_prfy_vars *pf)
{
	while (parse[pf->i][pf->i2])
	{
		if (parse[pf->i][pf->i2] != 34 && parse[pf->i][pf->i2] != '$')
			pf->prs[pf->x][pf->x2++] = parse[pf->i][pf->i2++];
		else if (parse[pf->i][pf->i2] != 34 && parse[pf->i][pf->i2] == '$')
			transformer(parse, pf);
		else
			pf->i2++;
	}
}

void	quo_prf_helper3(char **parse, t_quo_prfy_vars *pf)
{
	while (parse[pf->i][pf->i2])
	{
		if (parse[pf->i][pf->i2] != 39)
			pf->prs[pf->x][pf->x2++] = parse[pf->i][pf->i2++];
		else
			pf->i2++;
	}
}

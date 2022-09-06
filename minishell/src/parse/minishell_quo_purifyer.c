/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quo_purifyer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:13:41 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/07 01:49:50 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quo_transformer(char **parse, t_quo_prfy_vars *pf)
{
	char	*tmp;
	char	*env_var;
	int		b;
	int		ctrl;

	b = 0;
	parse[pf->i][pf->i2] = 0;
	ctrl = false;
	while (parse[pf->i][b] == 34)
		b++;
	tmp = ft_calloc(sizeof(char), ft_strlen(parse[pf->i]) - b);
	tmp = ft_strcpy(tmp, &(parse[pf->i][b]));
	parse[pf->i][pf->i2] = '$';
	env_var = ft_calloc(sizeof(char), ft_strlen(&(parse[pf->i][pf->i2])) - 1);
	b = 0;
	if (parse[pf->i][pf->i2 + 1] == '?')
		status_oprt(&env_var, &b, &ctrl, pf);
	while (parse[pf->i][pf->i2] != 34 && parse[pf->i][pf->i2])
		env_var[b++] = parse[pf->i][pf->i2++];
	if (ctrl == 0)
		env_var = env_converter(env_var);
	free(pf->prs[pf->x]);
	pf->prs[pf->x] = ft_strjoin(tmp, env_var);
	free(env_var);
	free(tmp);
}

void	transformer(char **parse, t_quo_prfy_vars *pf)
{
	char	*tmp;
	char	*env_var;
	int		b;
	int		ctrl;

	parse[pf->i][pf->i2] = 0;
	b = 0;
	ctrl = false;
	tmp = ft_calloc(sizeof(char), ft_strlen(parse[pf->i]));
	tmp = ft_strcpy(tmp, parse[pf->i]);
	parse[pf->i][pf->i2] = '$';
	env_var = ft_calloc(sizeof(char), ft_strlen(&(parse[pf->i][pf->i2])));
	if (parse[pf->i][pf->i2 + 1] == '?')
		status_oprt(&env_var, &b, &ctrl, pf);
	while (parse[pf->i][pf->i2])
		env_var[b++] = parse[pf->i][pf->i2++];
	if (ctrl == false)
		env_var = env_converter(env_var);
	free(pf->prs[pf->x]);
	pf->prs[pf->x] = ft_strjoin(tmp, env_var);
	free(env_var);
	free(tmp);
}

static int	quo_finder(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34)
			return (2);
		else if (s[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

static int	dbl_quo_cnt(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == '"')
			cnt++;
		s++;
	}
	return (cnt);
}

char	**quotes_purifyer(char **parse)
{
	t_quo_prfy_vars	pf;

	pf.i = 0;
	pf.x = 0;
	pf.prs = ft_calloc(sizeof(char *), ft_arglen(parse) + 1);
	while (parse[pf.i])
	{
		pf.i2 = 0;
		pf.x2 = 0;
		pf.prs[pf.x] = ft_calloc(sizeof(char), \
				(ft_strlen(parse[pf.i]) - dbl_quo_cnt(parse[pf.i]) + 1));
		if (quo_finder(parse[pf.i]) == 2)
			quo_prf_helper(parse, &pf);
		else if (quo_finder(parse[pf.i]) == 1)
			quo_prf_helper3(parse, &pf);
		else
			quo_prf_helper2(parse, &pf);
		pf.x++;
		pf.i++;
	}
	ft_free(parse);
	return (pf.prs);
}

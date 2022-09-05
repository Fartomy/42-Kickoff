/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_pipe_split_help_func.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:45:48 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/05 18:46:24 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_sp_helper3(t_pipe_split_vars *ps, char *s, char c)
{
	while (s[ps->i] && s[ps->i] != c)
	{
		if (s[ps->i] == 34)
		{
			ps->res[ps->index][ps->two_index++] = s[ps->i++];
			while (s[ps->i] != 34 && s[ps->i])
				ps->res[ps->index][ps->two_index++] = s[ps->i++];
			if (s[ps->i] == 34)
				ps->res[ps->index][ps->two_index++] = s[ps->i++];
		}
		else if (s[ps->i] == 39)
		{
			ps->res[ps->index][ps->two_index++] = s[ps->i++];
			while (s[ps->i] != 39 && s[ps->i])
				ps->res[ps->index][ps->two_index++] = s[ps->i++];
			if (s[ps->i] == 39)
				ps->res[ps->index][ps->two_index++] = s[ps->i++];
		}
		else
			ps->res[ps->index][ps->two_index++] = s[ps->i++];
	}
}

void	ft_pipe_sp_helper2(t_pipe_split_vars *ps, char *s)
{
	ps->res[ps->index][ps->two_index++] = s[ps->i++];
	while (s[ps->i] != 39 && s[ps->i])
		ps->res[ps->index][ps->two_index++] = s[ps->i++];
	if (s[ps->i] == 39 && s[ps->i])
		ps->res[ps->index][ps->two_index++] = s[ps->i++];
	while (s[ps->i])
		ps->res[ps->index][ps->two_index++] = s[ps->i++];
}

void	ft_pipe_sp_helper(t_pipe_split_vars *ps, char *s)
{
	ps->res[ps->index][ps->two_index++] = s[ps->i++];
	while (s[ps->i] != 34 && s[ps->i])
		ps->res[ps->index][ps->two_index++] = s[ps->i++];
	if (s[ps->i] == 34 && s[ps->i])
		ps->res[ps->index][ps->two_index++] = s[ps->i++];
	while (s[ps->i])
		ps->res[ps->index][ps->two_index++] = s[ps->i++];
}

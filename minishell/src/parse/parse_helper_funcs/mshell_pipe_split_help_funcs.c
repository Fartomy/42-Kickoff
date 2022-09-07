/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_pipe_split_help_funcs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:57:58 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/06 14:58:53 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_spl_helper(char **s, char *res, int *two_index, char c)
{
	res[(*two_index)++] = **s;
	(*s)++;
	while (**s != c && **s)
	{
		res[(*two_index)++] = **s;
		(*s)++;
	}
	if (**s == c && **s)
	{
		res[(*two_index)++] = **s;
		(*s)++;
	}
	while (**s != '\0')
	{
		res[(*two_index)++] = **s;
		(*s)++;
	}
}

void	pipe_spl_helper3(char ***s, char *res, int **two_index)
{
	res[(**two_index)++] = ***s;
	(**s)++;
	while (***s != 34 && ***s)
	{
		res[(**two_index)++] = ***s;
		(**s)++;
	}
	if (***s == 34)
	{
		res[(**two_index)++] = ***s;
		(**s)++;
	}
}

void	pipe_spl_helper2(char **s, char *res, int *two_index, char c)
{
	while (**s && **s != c)
	{
		if (**s == 34)
			pipe_spl_helper3(&s, res, &two_index);
		else if (**s == 39)
		{
			res[(*two_index)++] = **s;
			(*s)++;
			while (**s != 39 && **s)
			{
				res[(*two_index)++] = **s;
				(*s)++;
			}
			if (**s == 39)
			{
				res[(*two_index)++] = **s;
				(*s)++;
			}
		}
		else
		{
			res[(*two_index)++] = **s;
			(*s)++;
		}
	}
}

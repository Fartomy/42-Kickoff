/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_symbol_split_help_funcs.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:50:13 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 15:01:35 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	symbol_spl_helper(char **s, char *res, int *two_index, int c)
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

void	symbol_spl_helper2(char **s, char *res, int *two_index)
{
	if (**s == '>' && *(*s + 1) == '>')
	{
		while (**s == '>')
		{
			res[(*two_index)++] = **s;
			(*s)++;
		}
	}
	else if (**s == '<' && *(*s + 1) == '<')
	{
		while (**s == '<')
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

void	symbol_spl_helper4(char ***s, char *res, int **two_index)
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

void	symbol_spl_helper3(char **s, char *res, int *two_index)
{
	while (**s && **s != '>' && **s != '<')
	{
		if (**s == 34)
			symbol_spl_helper4(&s, res, &two_index);
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

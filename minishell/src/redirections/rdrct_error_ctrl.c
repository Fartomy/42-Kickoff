/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_error_ctrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:23:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirct_err_ctrl_for_output(char **parse)
{
	int	i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], ">") == 0 && parse[i + 1] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], ">") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& parse[i + 2] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], ">") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& (!ft_strcmp(parse[i + 2], ">") || !ft_strcmp(parse[i + 2], ">>") \
			|| !ft_strcmp(parse[i + 2], "<") || !ft_strcmp(parse[i + 2], "<<")))
			if (rdr_err_helper())
				return (0);
		i++;
	}
	return (1);
}

int	redirct_err_ctrl_for_input(char **parse)
{
	int	i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "<") == 0 && parse[i + 1] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], "<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& parse[i + 2] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], "<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& (!ft_strcmp(parse[i + 2], ">") || !ft_strcmp(parse[i + 2], ">>") \
			|| !ft_strcmp(parse[i + 2], "<") || !ft_strcmp(parse[i + 2], "<<")))
			if (rdr_err_helper())
				return (0);
		i++;
	}
	return (1);
}

int	redirct_err_ctrl_for_append(char **parse)
{
	int	i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], ">>") == 0 && parse[i + 1] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], ">>") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& parse[i + 2] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], ">>") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& (!ft_strcmp(parse[i + 2], ">") || !ft_strcmp(parse[i + 2], ">>") \
			|| !ft_strcmp(parse[i + 2], "<") || !ft_strcmp(parse[i + 2], "<<")))
			if (rdr_err_helper())
				return (0);
		i++;
	}
	return (1);
}

int	redirct_err_ctrl_for_heredoc(char **parse)
{
	int	i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "<<") == 0 && parse[i + 1] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], "<<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& parse[i + 2] == 0)
			if (rdr_err_helper())
				return (0);
		if (ft_strcmp(parse[i], "<<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 \
			&& (!ft_strcmp(parse[i + 2], ">") || !ft_strcmp(parse[i + 2], ">>") \
			|| !ft_strcmp(parse[i + 2], "<") || !ft_strcmp(parse[i + 2], "<<")))
			if (rdr_err_helper())
				return (0);
		i++;
	}
	return (1);
}

int	redirct_err_ctrl(char **parse)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (parse[i])
		i++;
	while (g_dt.symbol_tkn[x])
	{
		if (ft_strcmp(parse[i - 1], g_dt.symbol_tkn[x++]) == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			g_dt.status = 258;
			return (0);
		}
	}
	return (1);
}

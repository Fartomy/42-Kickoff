/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_error_ctrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:23:04 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/27 17:35:42 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int redirct_err_ctrl_for_output(char **parse)
{
	int i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], ">") == 0 && parse[i + 1] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if(ft_strcmp(parse[i], ">") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && parse[i + 2] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);	
		}
		else if(ft_strcmp(parse[i], ">") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && (ft_strcmp(parse[i + 2], ">") == 0 || \
				ft_strcmp(parse[i + 2], ">>") == 0 || ft_strcmp(parse[i + 2], "<") == 0 || ft_strcmp(parse[i + 2], "<<") == 0))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", parse[i + 2]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	redirct_err_ctrl_for_input(char **parse)
{
	int i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "<") == 0 && parse[i + 1] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if(ft_strcmp(parse[i], "<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && parse[i + 2] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);	
		}
		else if(ft_strcmp(parse[i], "<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && (ft_strcmp(parse[i + 2], ">") == 0 || \
				ft_strcmp(parse[i + 2], ">>") == 0 || ft_strcmp(parse[i + 2], "<") == 0 || ft_strcmp(parse[i + 2], "<<") == 0))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", parse[i + 2]);
			return (0);
		}
		i++;
	}
	return (1);
}

int redirct_err_ctrl_for_append(char **parse)
{
	int i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], ">>") == 0 && parse[i + 1] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if(ft_strcmp(parse[i], ">>") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && parse[i + 2] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);	
		}
		else if(ft_strcmp(parse[i], ">>") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && (ft_strcmp(parse[i + 2], ">") == 0 || \
				ft_strcmp(parse[i + 2], ">>") == 0 || ft_strcmp(parse[i + 2], "<") == 0 || ft_strcmp(parse[i + 2], "<<") == 0))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", parse[i + 2]);
			return (0);
		}
		i++;
	}
	return (1);
}

int redirct_err_ctrl_for_heredoc(char **parse)
{
	int i;

	i = 0;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "<<") == 0 && parse[i + 1] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if(ft_strcmp(parse[i], "<<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && parse[i + 2] == 0)
		{
			printf("minishell: syntax error near unexpected token `newline'\n");
			return (0);	
		}
		else if(ft_strcmp(parse[i], "<<") == 0 && ft_strcmp(parse[i + 1], " ") == 0 && (ft_strcmp(parse[i + 2], ">") == 0 || \
				ft_strcmp(parse[i + 2], ">>") == 0 || ft_strcmp(parse[i + 2], "<") == 0 || ft_strcmp(parse[i + 2], "<<") == 0))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", parse[i + 2]);
			return (0);
		}
		i++;
	}
	return (1);
}
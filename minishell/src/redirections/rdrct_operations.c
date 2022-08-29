/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrct_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:08:33 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/29 17:46:47 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rdr_runner(char **parse, char *file, int x)
{
	int fd;

	fd = 0;
	if(ft_strcmp(parse[x - 1], ">") == 0)
	{
		fd = open(file, O_WRONLY, 0777);
		dup2(fd, 1);
	}
	else if(ft_strcmp(parse[x - 1], "<") == 0)
	{
		fd = open(file, O_RDONLY, 0777);
		dup2(fd, 0);
	}
	builtin_or_smp_cmd_ctrl(parse);
	close(fd);
}

void	rdr_actuator(char *prs, int ctrl)
{
	int fd;
	
	fd = 0;
	if(ctrl == 1)
		fd = open(prs, O_RDWR | O_CREAT, 0644);
	else if(ctrl == 2)
	{
		char *buff;

		buff = NULL;
		fd = open(prs, O_RDONLY, 0444);
		if(fd == -1)
		{
			printf("minishell: %s: No such file or directory\n", prs);
			return ;			
		}
		read(fd, buff, 9999);
	}
/*	else if(ctrl == 3)
	{

	}
	else if(ctrl == 4)
	{
		
	}*/
	close(fd);
}

void	rdr_stream(char **parse)
{
	int x;

	x = 0;
	while(data.symbol_tkn[x])
		if(ft_strcmp(parse[0], data.symbol_tkn[x++]) == 0)
			return ;
	x = 0;
	while(parse[++x] && parse[x + 1] != 0)
	{
		if(ft_strcmp(parse[x], ">") == 0)
			rdr_actuator(parse[x + 1], 1);
		else if(ft_strcmp(parse[x], "<") == 0)
			rdr_actuator(parse[x + 1], 2);
		else if(ft_strcmp(parse[x], "<<") == 0)
			rdr_actuator(parse[x + 1], 3);
		else if(ft_strcmp(parse[x], ">>") == 0)
			rdr_actuator(parse[x + 1], 4);
	}
	rdr_runner(parse, parse[x], x);
}

void	ft_redirecton(char **parse)
{
	if(!redirct_err_ctrl_for_output(parse))
		return ;
	if(!redirct_err_ctrl_for_input(parse))
		return ;
	if(!redirct_err_ctrl_for_append(parse))
		return ;
	if(!redirct_err_ctrl_for_heredoc(parse))
		return ;
	if(!redirct_err_ctrl(parse))
		return ;
	rdr_stream(parse);
}
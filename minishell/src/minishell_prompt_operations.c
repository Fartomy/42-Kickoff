/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 00:27:01 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/03 14:42:44 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int pipe_cnt(char **s)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (ft_strcmp(s[i], "|") == 0)
			cnt++;
	}
	return (cnt);
}

void piped_command(char **parse)
{
	int ctrl;
	int i;
	int p;
	int x;
	int **pfd;
	int *pids;

	ctrl = pipe_err_ctrl(parse);
	if (ctrl == 0)
		return;
	i = pipe_cnt(parse) + 1;
	pfd = malloc(sizeof(int *) * i);
	x = -1;
	while (++x < i)
		pfd[x] = malloc(sizeof(int) * 2);
	x = -1;
	while (++x < i)
		pipe(pfd[x]);
	pids = ft_calloc(i, sizeof(int));
	x = -1;
	p = -1;
	while (++p <= i && parse[++x] != 0)
	{
		if (ft_strcmp(parse[x], "|") == 0)
			x++;
		pids[p] = fork();
		if (pids[p] == 0)
		{
			if (p == 0)
			{
				dup2(pfd[p + 1][1], 1);
				close(pfd[p][1]);
				close(pfd[p][0]);
			}
			else if (p + 1 != i)
			{
				dup2(pfd[p][0], 0);
				dup2(pfd[p + 1][1], 1);
				close(pfd[p][1]);
				close(pfd[p][0]);
			}
			else if (p + 1 == i)
			{
				dup2(pfd[p][0], 0);
				close(pfd[p][1]);
				close(pfd[p][0]);
			}
			simple_cmd(&parse[x]);
			exit(0);
		}
		close(pfd[p][1]);
		close(pfd[p][0]);
	}
	p = -1;
	while(++p < i)
		wait(NULL);
}

void builtin_command(char **parse)
{
	if (ft_strcmp(parse[0], data.built_in_tkn[0]) == 0)
		ft_echo(parse);
	else if (ft_strcmp(parse[0], data.built_in_tkn[1]) == 0)
		ft_cd(parse);
	else if (ft_strcmp(parse[0], data.built_in_tkn[2]) == 0)
		ft_pwd(parse);
	else if (ft_strcmp(parse[0], data.built_in_tkn[3]) == 0)
		ft_export(parse);
	else if (ft_strcmp(parse[0], data.built_in_tkn[5]) == 0)
		ft_env(parse);
	else if (ft_strcmp(parse[0], data.built_in_tkn[4]) == 0)
		ft_unset(parse);
	else if (ft_strcmp(parse[0], data.built_in_tkn[6]) == 0)
		ft_exit(parse);
	ft_free(parse);
}

void builtin_or_smp_cmd_ctrl(char **parse)
{
	int i;
	int x;
	bool builtin_ctrl;

	i = -1;
	builtin_ctrl = false;
	parse = ft_implt_split(parse[0], ' ');
	parse = quotes_purifyer(parse);
	i = 0;
	while (parse[i])
	{
		x = 0;
		while (ft_strcmp(parse[i], data.built_in_tkn[x]) != 0 && data.built_in_tkn[x])
			x++;
		if (ft_strcmp(parse[i], data.built_in_tkn[x]) == 0)
		{
			builtin_ctrl = true;
			builtin_command(parse);
			break;
		}
		i++;
	}
	if (builtin_ctrl == false)
		cmd_finder(parse);
}

void simple_cmd(char **parse)
{
	bool symbol_ctrl;
	int i;
	int x;
	
	i = 0;
	symbol_ctrl = false;
	parse = ft_symbol_split(parse[0]);
	while (parse[i])
	{
		x = 0;
		while (ft_strcmp(parse[i], data.symbol_tkn[x]) != 0 && data.symbol_tkn[x])
			x++;
		if (ft_strcmp(parse[i], data.symbol_tkn[x]) == 0)
		{
			symbol_ctrl = true;
			ft_redirecton(parse);
			break;
		}
		i++;
	}
	if (symbol_ctrl == false)
		builtin_or_smp_cmd_ctrl(parse);
	ft_free(parse);
}

void cmd_router(char **parse)
{
	int i;
	bool simple_cmd_ctrl;

	i = 0;
	simple_cmd_ctrl = false;
	while (parse[i])
	{
		if (ft_strcmp(parse[i], "|") == 0)
		{
			simple_cmd_ctrl = true;
			piped_command(parse);
			break;
		}
		i++;
	}
	if (simple_cmd_ctrl == false)
		simple_cmd(parse);
}
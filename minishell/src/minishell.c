/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:37:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:59:34 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minidata	g_dt;

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_dt.env = storage_and_copy(envp);
	g_dt.export = storage_and_copy(envp);
	g_dt.export = export_sorter(g_dt.export);
	set_symbol_token(g_dt.symbol_tkn);
	set_builtin_token(g_dt.built_in_tkn);
	prompt();
}

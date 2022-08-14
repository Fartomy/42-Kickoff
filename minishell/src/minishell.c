/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:37:36 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/13 18:09:12 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minidata data;

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	data.env = envp;
	set_symbol_token(data.symbol_tkn);
	set_builtin_token(data.built_in_tkn);
	prompt();
}
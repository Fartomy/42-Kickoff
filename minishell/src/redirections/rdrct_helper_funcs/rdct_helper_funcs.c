/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdct_helper_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:08:25 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:38:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	rdr_err_helper(void)
{
	printf("minishell: syntax error near unexpected token `newline'\n");
	g_dt.status = 258;
	return (1);
}

void	heredoc_oprt_helper(char *prs, int *fd2)
{
	char	*str;

	signal(SIGINT, heredc_ctrl_c);
	while (1)
	{
		str = readline(">_ ");
		if (ft_strcmp(prs, str) == 0)
			break ;
		str = ft_strjoin(str, "\n");
		write(fd2[1], str, ft_strlen(str));
	}
}

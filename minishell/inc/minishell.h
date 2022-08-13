/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:40:55 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/08/13 17:58:14 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PRP "\033[0;35m"
# define WHT "\033[0;37m"
# define RED "\033[0;31m"
# define YLW "\033[0;33m"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_minishell
{
    char **env;
    char **parse;
    char *symbol_tkn[6];
    char *built_in_tkn[8];
}              t_minidata;

extern t_minidata data;

// tokens and tools
void	set_builtin_token(char **bl_token);
void	set_symbol_token(char **sy_token);
void    ft_free(char **str);

// implemented funcs
int     ft_arglen(char **arg);
int	    ft_strcmp(const char *s1, const char *s2);
char	**ft_big_implt_split(char const *s, char c);
char	**ft_implt_split(char const *s, char c);
char    **ft_pipe_split(char const *s, char c);
char	**ft_symbol_split(char *s);
char    **quotes_purifyer(char **parse);

// runner funcs
void	cmd_finder(char **parse);

//prompts
void    prompt(void);

// builtin commands
void    ft_echo(char **parse);
void    ft_pwd(void);

#endif

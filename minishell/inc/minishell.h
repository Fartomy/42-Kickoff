/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:40:55 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/01 17:30:11 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PRP "\033[0;35m"
# define WHT "\033[0;37m"
# define RED "\033[0;31m"
# define YLW "\033[0;33m"

# include <stdbool.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_minishell
{
    char **env;
    char **export;
    char **parse;
    char *symbol_tkn[6];
    char *built_in_tkn[8];
    int  fd;
    int  fd2;
}              t_minidata;

extern t_minidata data;

// tokens and tools
char	**storage_and_copy(char **env);
char 	**ft_rrealloc(char **ptr, size_t size);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_realloc(void *ptr, size_t size);
void	set_builtin_token(char **bl_token);
void	set_symbol_token(char **sy_token);
void    ft_free(char **str);
int	    ft_strcmp(const char *s1, const char *s2);
int     ft_arglen(char **arg);
int	    cmd_space_ctrl(char *cmd);

// env tools
char    *env_converter(char *str);
char    *env_getter(char *str);
char    *env_name_getter(char *var);
char    **export_sorter(char **envp);
int     equal_finder(char *var);

// implemented funcs
char	**ft_big_implt_split(char const *s, char c);
char	**ft_implt_split(char const *s, char c);
char    **ft_pipe_split(char const *s, char c);
char	**ft_symbol_split(char *s);
char    **quotes_purifyer(char **parse);

// redirections
void    ft_redirecton(char **parse);
void    rdr_stream(char **parse);
void    first_argis_symbol(char **parse);
void    rdr_runner(char **parse, int x);
void    heredoc_oprt(char *prs, int *fd2);
int     redirct_err_ctrl_for_output(char **parse);
int     redirct_err_ctrl_for_input(char **parse);
int     redirct_err_ctrl_for_append(char **parse);
int     redirct_err_ctrl_for_heredoc(char **parse);
int     redirct_err_ctrl(char **parse);
int     rdr_actuator(char *prs, int ctrl);
void	rdr_input(int ctrl);

// signals
void	ctrl_backslash(int sig);
void    heredc_ctrl_c(int sig);
void	ctrl_c(int sig);
void	ctrl_d(void);

// runner funcs
void	cmd_finder(char **parse);

// prompts operations funcs
void    prompt(void);
void	builtin_command(char **parse);
void	builtin_or_smp_cmd_ctrl(char **parse);
void	simple_cmd(char **parse);
void	cmd_router(char **parse);

// builtin commands
void    ft_echo(char **parse);
void    ft_pwd(char **parse);
void    ft_cd(char **parse);
void    ft_export(char **parse);
void    ft_env(char **parse);
void	ft_unset(char **parse);
void	ft_exit(char **parse);

#endif

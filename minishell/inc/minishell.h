/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:40:55 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 14:58:43 by ftekdrmi         ###   ########.fr       */
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
	char	**env;
	char	**export;
	char	**parse;
	char	*symbol_tkn[6];
	char	*built_in_tkn[8];
	int		fd;
	int		fd2;
	int		status;
}	t_minidata;

typedef struct s_quo_prfy_vars
{
	int		i;
	int		i2;
	int		x;
	int		x2;
	char	**prs;
}	t_quo_prfy_vars;

typedef struct s_export_vars
{
	int		i;
	char	*tmp;
	char	*env_name;
}		t_export_vars;

typedef struct s_cmd_finder_vars
{
	char	**paths;
	char	**opt;
	char	*join;
	int		i;
	int		x;
	bool	ctrl;
}	t_cmd_finder_vars;

extern t_minidata	g_dt;

// tokens and tools
char	**storage_and_copy(char **env);
char	**ft_rrealloc(char **ptr, size_t size);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_realloc(void *ptr, size_t size);
void	set_builtin_token(char **bl_token);
void	set_symbol_token(char **sy_token);
void	ft_free(char **str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_arglen(char **arg);
int		cmd_space_ctrl(char *cmd);

// env tools
char	*env_converter(char *str);
char	*env_getter(char *str);
char	*env_name_getter(char *var);
char	**export_sorter(char **envp);
int		equal_finder(char *var);

// implemented funcs
char	**ft_implt_split(char *s, char c);
char	**ft_pipe_split(char *s, char c);
char	**ft_symbol_split(char *s);
char	**quotes_purifyer(char **parse);

//	helped funcs

//pipe_split_help_funcs
void	pipe_spl_helper(char **s, char *res, int *two_index, char c);
void	pipe_spl_helper2(char **s, char *res, int *two_index, char c);
void	pipe_spl_helper3(char ***s, char *res, int **two_index);
//pipe_command_help_funcs
void	pipe_cmd_body(int **pfd, char **parse, int *p, int i);
void	pipe_cmd_first_arg(int **pfd, int *p);
void	pipe_cmd_betw_arg(int **pfd, int *p);
void	pipe_cmd_last_arg(int **pfd, int *p);
void	pipe_cmd_close(int **pfd, int p);
void	pipe_cmd_wait(int i);
void	pipe_cmd_free(int i, int *pids, int **pfd);
void	pipe_cmd_storage(int ***pfd, int **pids, int i, int *p);
//symbol_split_help_funcs
void	symbol_spl_helper(char **s, char *res, int *two_index, int c);
void	symbol_spl_helper2(char **s, char *res, int *two_index);
void	symbol_spl_helper4(char ***s, char *res, int **two_index);
void	symbol_spl_helper3(char **s, char *res, int *two_index);
//redirect_operations_help_funcs
void	rdr_runner_helper(char **parse, int *fd2);
char	*rdr_stream_mini_helper(char **parse, int x);
int		rdr_stream_helper(char **parse, int *ctrl, int x);
//quotes_purifyer_help_funcs
void	status_oprt(char **env_var, int *b, int *ctrl, t_quo_prfy_vars *pf);
void	quo_prf_helper(char **parse, t_quo_prfy_vars *pf);
void	quo_prf_helper2(char **parse, t_quo_prfy_vars *pf);
void	quo_prf_helper3(char **parse, t_quo_prfy_vars *pf);
void	quo_transformer(char **parse, t_quo_prfy_vars *pf);
void	transformer(char **parse, t_quo_prfy_vars *pf);
//ft_cd_help_funcs
void	uptd_old_pwd_env(void);
void	uptd_old_pwd_export(void);
void	uptd_pwd_env(void);
void	uptd_pwd_export(void);
//ft_export_help_funcs
void	exprt_addvar_mini_help(t_export_vars *exp, int *env_ctrl, \
									int *x, char *var);
int		export_add_var_helper(t_export_vars *exp, char *var);
int		export_add_var_helper2(t_export_vars *exp, char *var);
int		export_add_var_body_helper(t_export_vars *exp, char *var);
void	export_add_var_equal(t_export_vars *exp, char *var);
//ft_unset_help_funcs
int		unset_env_helper(int x);
int		unset_export_helper(int x);
void	unset_error(char **parse, int i);
//cmd_finder_help_funcs
int		cmd_fdr_ifnot_path(t_cmd_finder_vars *cmf, char **parse);
int		cmd_fdr_ifpt_helper(t_cmd_finder_vars *cmf, char **parse);
int		cmd_fdr_ifpt_helper2(t_cmd_finder_vars *cmf, char **parse);
void	cmd_fdr_if_path(t_cmd_finder_vars *cmf, char **parse);
//redirections_help_funcs
int		rdr_err_helper(void);
void	heredoc_oprt_helper(char *prs, int *fd2);

// pipes
void	piped_command(char **parse);
int		pipe_err_ctrl(char **parse);

// redirections
void	ft_redirecton(char **parse);
void	rdr_stream(char **parse);
void	first_argis_symbol(char **parse);
void	rdr_runner(char **parse, int x);
void	heredoc_oprt(char *prs, int *fd2);
int		redirct_err_ctrl_for_output(char **parse);
int		redirct_err_ctrl_for_input(char **parse);
int		redirct_err_ctrl_for_append(char **parse);
int		redirct_err_ctrl_for_heredoc(char **parse);
int		redirct_err_ctrl(char **parse);
int		rdr_actuator(char *prs, int ctrl);
void	rdr_input(int ctrl);

// signals
void	ctrl_backslash(int sig);
void	heredc_ctrl_c(int sig);
void	ctrl_c(int sig);
void	ctrl_d(void);

// runner funcs
void	cmd_finder(char **parse);
void	cmd_runner(char *path, char **opt);

// prompts operations funcs
void	prompt(void);
void	builtin_command(char **parse);
void	builtin_or_smp_cmd_ctrl(char **parse);
void	simple_cmd(char **parse);
void	cmd_router(char **parse);

// builtin commands
void	ft_echo(char **parse);
void	ft_pwd(char **parse);
void	ft_cd(char **parse);
void	ft_export(char **parse);
void	ft_env(char **parse);
void	ft_unset(char **parse);
void	ft_exit(char **parse);

#endif

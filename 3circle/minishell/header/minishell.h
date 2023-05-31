/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:15:29 by wonljeon          #+#    #+#             */
/*   Updated: 2023/04/02 13:06:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include "../src/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

extern int	g_exit_code;
typedef struct s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	char			*envs;
}		t_lst;

typedef struct s_file
{
	int		infile;
	int		infile_err;
	int		outfile;
	int		err_file;
}	t_redirect;

typedef struct s_a
{
	char	**cut_pipe;
	char	**cmd;
	char	***cmd_opt;
	char	***redirect;
	size_t	**limit_quote;
	size_t	here_doc_cnt;
	size_t	quote_flag;
	size_t	opt_cnt;
	size_t	redirect_cnt;
	size_t	execve_cnt;
}	t_cmd;

typedef struct s_b
{
	size_t	cur;
	char	*err_name;
	int		syntax_err_index;
	int		err_flag[128];
	int		err;
	int		err_idx[2];
}	t_syntax;

typedef struct s_pipex
{
	pid_t		*pid;
	int			*is_cmd;
	int			last_execve_cmd;
	char		**path;
	char		**ep;
	char		*line;
	char		**builtin;
	size_t		pipe_cnt;
	int			*execve_cmd;
	int			*fds;
	int			temp;
	int			tmp;
	int			err;
	int			comment_flag;
	t_syntax	*syntax;
	t_redirect	*redirect;
	t_cmd		*cmd;
	t_lst		*head;
	t_lst		*tail;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		f;
}	t_pipex;

void	check_pipe_cnt(int pipe_cnt);
void	change_dollars(t_lst **head, t_lst **tail, char **lst);
void	jasik_sig(int sig);
void	signal_cmd(int sig);
int		ft_strcmp(const char *s1, const char *s2);
void	lst_insert_orm(t_lst **head, t_lst **tail, char *envp);
void	ft_export(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt);
void	print_export_orm(t_lst **head, t_lst **tail);
void	print_export_orm_without_quote(t_lst **head, t_lst **tail);
int		ft_strchr_num(const char *str, int c);
int		ft_isalnum_for_export(int c);
char	*find_quote_for_export(char *cmd);
void	find_special_middle_for_export_2(char **str, int i[]);
void	find_special_middle_for_export_3(char **str, int i[]);
char	*find_special_middle_for_export(char *str, int i[]);
int		free_and_dup(t_lst *cur, char *cmd, char *equal_cmd);
void	for_25(int	*i, char **equal_cmd, char *cmd);
int		double_check(t_lst **head, int i, t_lst **tail, char *cmd);
char	*help(char **cmdline, int i[]);
int		check_end_slash(char **cmdline);

// builtin_functions
void	ft_unset(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt);
char	*find_quote_for_unset(char *cmd);
void	ft_env(t_lst *head, t_lst *tail, char **cmdline, int pipe_cnt);
char	*removex_slash(char *str);
void	ft_pwd(t_lst **head, t_lst **tail);
void	ft_cd(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt);
char	*find_env_value(char *key, t_lst **head, t_lst **tail);
void	free_cd_all(char *a, char *b, char *c);
void	ft_echo(char **cmdline);
char	*find_special_middle_for_echo(char *str);
char	*check_slash_for_echo(char *str);
int		check_newline(char **cmdline, int *i);
void	print_echo(char **cmdline, int j, int n);
void	move_back_and_set_pwd(t_lst **head, t_lst **tail, int pipe_cnt);
void	move_home_and_set_pwd(t_lst **head, t_lst **tail, int pipe_cnt);
char	*wave_add(t_lst **head, t_lst **tail);
int		free_and_dup(t_lst *cur, char *cmd, char *equal_cmd);
void	for_25(int	*i, char **equal_cmd, char *cmd);
int		for_25_2(int i, char *cmd, t_lst **head, t_lst **tail);
int		for_25_3(int i, t_lst **head, t_lst **tail, char *cmd);
int		double_check(t_lst **head, int i, t_lst **tail, char *cmd);
int		ft_isalnum_for_export(int c);
void	init_shell(t_pipex *pipex);
char	*actual_change(t_lst **head, t_lst **tail, char *tmp);
void	free_util(t_pipex *pipex);
void	end_shell(t_pipex *pipex);
int		dollar_alnum(int c);
void	free_four(char *tmp, char *front, char *back, char *ret);
void	dollar_mul(char **lst, int i[3]);
void	free_two(char *a, char *b);
void	free_three(char *a, char *b, char *c);
void	dollar_chn(t_lst **head, t_lst **tail, char **lst, int i[]);
void	change_dollars(t_lst **head, t_lst **tail, char **lst);
void	here_doc_dollar(char **lst, int i[]);
void	for_yishipoh(char **lst, int i[]);
void	init_num_arr(int i[]);
void	set_num_arr(int i[]);
void	node_free(t_lst *node);
void	exit_shell(t_pipex *pipex, t_lst **node, int i);
int		is_int(char *str);
void	ft_exit_util(t_pipex *p, t_lst **head);
void	ft_exit(t_pipex *p, t_lst **head);
void	set_oldpwd_pwd(t_lst **head, t_lst **tail);
void	ft_move_home(t_lst **head, t_lst **tail, int pipe_cnt);
void	ft_move_back(t_lst **head, t_lst **tail, int pipe_cnt);

// ft_functions
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa(int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

// pipe_util_functions
void	create_pipe(t_pipex *pipex);
void	close_pipes(t_pipex *p);

// redirect_functions
void	handle_syntax_err(t_pipex *pipex);
void	get_file(t_pipex *pipex, size_t i, size_t j, int f);
void	infile_err(t_pipex *pipex, int fd, char *err);
void	here_doc(t_pipex *pipex, size_t i, size_t j, char *line);
void	print_err_file(t_pipex *p);
void	get_file(t_pipex *pipex, size_t i, size_t j, int f);
void	jasik_sig(int sig);
void	child_builtin(t_pipex *p, t_lst **head, t_lst **tail);
char	**cmdline_init(t_pipex *p);
size_t	count_cmd(char **cmds);

// util_funcitons
void	two_pointer_free(char **str);
void	three_pointer_free(char ***str);
void	redirect_flag_init(t_pipex *pipex);
void	syntax_err_continue(t_pipex *pipex, int f);
void	end_shell(t_pipex *pipex);
char	*get_next_line(int fd);
int		is_builtin(t_pipex *p);
void	builtin(t_pipex *p, t_lst **head, t_lst **tail);
int		built_in_init(t_lst **head, t_lst **tail, char **ep, t_pipex *p);
void	ft_exit(t_pipex *p, t_lst **head);
void	init_ep(t_pipex *pipex, t_lst **head);

// syntax_functions
void	print_syntax_err(t_pipex *pipex);
void	check_pipe_syntax(t_pipex *pipex, char *line, size_t i, int f);
void	check_semi_colon_back_slash(t_pipex *pipex, char *line);
void	occur_syntax_err(t_pipex *pipex, size_t i, size_t j, char *err_file);
void	check_redirect_syntax(t_pipex *p, int i, int j);
void	is_space(t_pipex *p, char *line);

// cmd_parsing
void	cut_pipe(t_pipex *pipex, char *line, size_t point);
void	pass_redirect(char *line, size_t *i, size_t *ret);
void	pass_quote(t_pipex *pipex, char *line, size_t *i, char c);
void	execve_cmd_init(t_pipex *p, char *line, int i);
void	init_pipe_cnt(t_pipex *pipex, char *line);
void	quote_pass_util(t_pipex *pipex, char *line, size_t *i, size_t *ret);
void	quote_pass_util1(t_pipex *pipex, char *line, size_t *i, size_t *ret);
void	pass_quote1(char *line, size_t *i, char c);
void	start_shell(t_pipex *pipex, t_lst **head, t_lst **tail, char *tmp);
char	*redirect(t_pipex *pipex, char *line, size_t *i);
size_t	redirect_cnt(t_pipex *pipex, char *line);
char	**cmd_split(t_pipex *pipex, char *line, int k);
void	execute(t_pipex *p, t_lst **head, t_lst **tail);
int		discriminate_redirect(char *line, size_t *i);
char	*quote_trim(t_pipex *p, char *line, size_t *i, char *a);

// execve_function_util
char	*cmd_root(t_pipex *pipex, char *cmd);
void	print_err(t_pipex *p, char *cmd, char *msg);
void	sub_dup2(t_pipex *p);
void	priority_redirect(t_pipex *p);
void	wait_child(t_pipex *p, pid_t pid);
void	init_is_cmd_util(t_pipex *p, int i);
void	init_is_cmd(t_pipex *p);
void	ft_execve_util(t_pipex *p, char *temp);
void	ft_execve(t_pipex *p, t_lst **head);
void	hand(int signum);

#endif

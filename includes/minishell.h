/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:35:48 by hoslim            #+#    #+#             */
/*   Updated: 2023/02/14 15:01:26 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ERROR 1
# define SUCCESS 0
# define FAIL -1
# define T_WORD 10
# define T_PIPE 11
# define T_REDI 12
# define T_NULL 13

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <termios.h>
# include <term.h>
# include "../srcs/parsing/test.h"

typedef struct s_info
{
	struct s_cmd	*cmd;
	char			**en;
}	t_info;

typedef struct s_cmd
{
	int				type;
	int				exec_flag;
	int				close_flag;
	int				parent_flag;
	int				parse_flag;
	char			*str;
	struct s_cmd	*left;
	struct s_cmd	*right;
	pid_t			pid;
}	t_cmd;

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t num);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
int		ft_isalpha(int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

t_info	*init_info(char **envp);
t_cmd	*init_cmd(void);
void	shell_exit(t_info *info);

void	start_shell(t_info *info);
void	handle_parent(void);
void	handle_signal(void);
void	handle_child(void);
void	print_prompt(void);

int		error(t_info *info, char *s, int flag);
int		hs_error_return(t_info *info, t_cmd *cmd, char *s);
void	free_cmd(t_cmd *cmd, char *buf);
void	free_info(t_info *info);
void	free_parse(char **str);
char	*hs_parsing_cmd(char ***envp, char *cmdline);
int		check_argc(char *str);

void	parsing_cmd(t_info *info, char *buf);
void	hs_cmd(t_cmd *cmd, char ***envp);
int		check_cmd_exec(t_cmd *cmd, char ***envp);

int		check_type(t_cmd *cmd, char *buf);
int		count_line(char **line);
void	hs_parse_pipe(t_cmd *cmd, char *buf, int i);
void	hs_parse_redi(int idx, t_cmd *cmd, char *buf, int flag);
void	parse_redi(t_cmd *cmd);
void	hs_parse_redi_double(t_cmd *cmd);
int		hs_check_heredoc(char *str);
void	make_temp(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd, char ***envp);
int		check_cmd_exec(t_cmd *cmd, char ***envp);
int		hj_envp_name_chk(char *str);
int		hj_compare_check(char *str);

void	hs_search_tree(t_cmd *cmd, char ***envp);

void	hs_redirect(t_cmd *cmd, char ***envp);
int		count_redi(t_cmd *cmd);
void	redi_pipe(t_cmd *cmd, char ***envp);

void	hs_pipeline(t_cmd *cmd, char ***envp);
char	*pipe_parsing_cmd(char **path, char *cmd);
char	**pipe_parsing_envp(char ***envp);
void	hs_proc_child(t_cmd *cmd, char ***envp, int prev[2], int now[2]);
void	pipe_word(int parent[2], int child[2], t_cmd *cmd, char ***envp);
int		**pipe_open(t_cmd *cmd);
void	close_other(int **fd, int cur, int count);
void	close_all(int **fd, int cur);
void	free_fd(int **fd, int count);

int		hs_check_builtin(t_cmd *cmd, char ***envp);
void	hs_exec_builtin(t_cmd *cmd, char ***envp);
int		check_option(char **str, int *option);
void	ft_env(t_cmd *cmd, char ***envp);
void	ft_pwd(t_cmd *cmd);
void	ft_export(t_cmd *cmd, char ***envp);
void	ft_unset(t_cmd *cmd, char ***envp);
int		ft_echo(t_cmd *cmd, char ***envp);
void	ft_cd(t_cmd *cmd, char ***envp);
int		ft_exit(t_cmd *cmd, char ***envp);

void	exit_get_code(pid_t pid);

int		check_key(char *envp, char *src);
int		hs_check_envp(char ***envp, char *str);
char	*parse_env_value(char *key, char ***envp);
void	swap_env(char ***envp, char *src, char *key);
char	**hj_envp_del(char **envp, char *str);
char	**hj_envp_bigtaging(char *str);
char	*hj_echo_join(char **str, int i);

char	**hj_split_cmd(char *str, char **envp);
char	**hj_redc_spilit(char *str);
char	**hj_export_insert(char **str, char **envp);

#endif

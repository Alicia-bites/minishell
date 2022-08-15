/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 15:21:11 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libft.h"
# include "minishell_enum.h"
# include "minishell_message.h"

# define SMB_NAME "smbash"

# define WRONG_CMD 127
# define MALLOC_FAILURE 1
# define MISSING_QUOTES 2
# define MISPLACED_PIPE 2
# define MISPLACED_REDIR 2
# define SPECIAL_CHAR 2
# define SEMICOLON 2
# define DOUBLE_PIPE 2
# define MISSING_BRACKET 2
# define ERR_DOLLAR 2
# define BAD_SUB 1

// ARGUMENT DELIMITER AS: cmd -arg1 -arg2
# define ARG_DEL '-'
// DIRECTORY SEPARATOR AS: /home/user
# define DIR_SEP "/"
// ENVIRONMENT SEPARATOR AS: HOME=/home/user
# define ENV_SEP '='
// ENVIRONMENT FIELD SEPARATOR AS: PATH=/usr/bin:/usr/local/bin
# define ENV_FIELD_SEP ':'
// EXPORT PREFIX AS: declare -x HOME="/home/user"
# define EXP_PREFIX "declare -x "
// DEFAULT FILE DESCRIPTOR VALUE FOR PIPING AND REDIRECTION PROCESS
# define FD_NOT_INIT -999999

// STANDARD ENVIRONMENT VARIABLE NAME
# define ENV_HOME_NAME "HOME"
# define ENV_OLDPWD_NAME "OLDPWD"
# define ENV_PATH_NAME "PATH"
# define ENV_PWD_NAME "PWD"

// BUILTIN FLAG
# define BUILT_CD "cd"
# define BUILT_ECHO "echo"
# define BUILT_ENV "env"
# define BUILT_EXIT "exit"
# define BUILT_EXIT_STATUS "$?"
# define BUILT_EXPORT "export"
# define BUILT_PWD "pwd"
# define BUILT_UNSET "unset"

//HEREDOC
# define HD_BIN_FALSE "/usr/bin/false"
# define HD_BIN_TRUE "/usr/bin/true"
# define HD_TMP_DIR "/tmp"
# define HD_PREFIX "heredoc :"
# define HD_MSG_EOF "here-document delimited by end-of-file"
# define HD_CHRSET "\"\'"

// BUILTIN CHARSET TO CHECK ARGUMENT STRUCTURE
# define CHRSET_EXPORT "`~!@#$%^&*()-[]{}|:;\"\'<,>.?/ "
# define CHRSET_PWD "()"
# define CHRSET_UNSET "`~!@#$%^&*()-[]{}|:;\"\'<,>.?/"

typedef struct s_chartype {
	char			character;
	int				length;
	int				n_double;
	int				n_single;
	t_enum_chartype	type;
}	t_chartype;

typedef struct s_global {
	int				readline;
	int				seen_tok_cmd;
	int				*saved_pos;
	long long		exit;
}	t_global;

typedef struct s_cursor {
	int			i;
	int			k;
}	t_cursor;

typedef struct s_dart {
	int			i;
	int			j;
	int			s;
	int			d;
}	t_dart;

typedef struct s_exp_arg {
	char		*str;
	t_ulist		*envp;
	int			*tab;
}	t_exp_arg;

typedef struct s_position
{
	int	pos;
	int	move_cursor;
	int	n_expansions;
}	t_position;

typedef struct s_expanded {
	int					index;
	char				*expanded;
	struct s_expanded	*prev;
	struct s_expanded	*next;
	t_ulist				*envp;
}	t_expanded;

// STRUCTURE OF ENVIRONMENT VARIABLE
typedef struct s_env {
	char		*key;
	char		*value;
	t_var_view	var_view;
}	t_env;

// STRUCTURE OF COMMAND LIST TO BE EXECUTED
typedef struct s_cmd
{
	t_list		**tok_lst;
	t_list		*tok_node;
	t_ulist		**env_lst;
	t_toktype	toktype;
	char		*arg;
	size_t		n_arg;
	char		**fullcmd; //-> liste chainee de char qui contient la commande + les arguments
	char		*fullpath; //-> chemin absolu de la ou se trouve la commande
	char		*hd_name;
	int			hd_r;
	int			fd_r; //->  file descriptor read
	int			fd_w; //-> file descriptor write
	int			pfd_r; //-> pipe file descriptor
	int			pfd_w; //-> pipe file descriptor
	int			access; //-> verif que la commande existe, ou est executable, en gros c'est le
						// -> lfag pour savoir si on peut lancer la commande et sinon, message d'erreur
}		t_cmd;

//input_handler
int					get_input(int *err, t_ulist **envp);
void				exit_minishell(t_list **token_list, t_ulist **envp);
void				handle_str(char **str, t_list **token_list, int *err,
						t_ulist **envp);

//parsing
int					ft_parse(char *str, t_list **token_list, int *err, t_ulist *envp);
void				create_input_list(t_chartype **input_list, char *str);
void				sort_inputs(char **inputs);
char				**store_built_ins(void);
t_list				*create_list(char *str, int i, t_toktype e_toktype);
void				print_lst(t_list *lst);
int					handle_unknown_command(t_list *inputs_lst);
int					is_not_clone(char *str);
int					is_not_empty(char *str);
void				count_quotes(char *str, t_chartype *input_list);
int					count_double(char *str);
int					count_single(char *str);

//lexer
int					lex_pipe(char *str, int *err);
int					lex_quote(char *str, int *err);
// int					count_double_for_lexer(char *str);
// int					count_single_for_lexer(char *str);
void				count_quotes_lexer(int *s, int *d, char *str);
int					lex_brackets(char *str, int *err);
int					lexer(char *str, int *err);
int					lex_dollar(char *str, int *err);
int					lex_redir(char *str, int *err);
int					lex_space(char *str, int *err);
int					lex_sym(char *str, int *err);
int					between_quotes(char *str, int pos);
int					between_single_quotes(char *str, int pos);

//expansions
int					bracket_is_after_dollar(char *str, int pos);
t_expanded			*create_dollar_list(char *str, int index);
int					count_op(char *str);
int					count_op_in_expanded_list(t_expanded *expanded_list);
char				*expand_dollar(t_exp_arg exp_arg, int **tab);
void				find_expansions(t_exp_arg exp_arg, t_expanded **expanded_list, int *full_size);
int					find_total_number_op(int *tab);
int					found_operator(char *str);
void				set_minus_one_tab(int *tab, size_t n);
void				ft_lstadd_back_dollar(t_expanded **alst, t_expanded *new);
t_expanded			*ft_lstnew_dollar(char *str, int i);
void				ft_lstclear_back_dollar(t_expanded **lst);
void				ft_lstclear_dollar(t_expanded **lst);
char				*ft_getenv(char *var, t_ulist *envp);
int					get_full_size(t_expanded *expanded_list);
void				get_expanded(t_exp_arg exp_arg, t_expanded **expanded_list, int i, int *varsize);
int					handle_dollar_brackets(t_exp_arg exp_arg, int i,
						t_expanded **expanded_list, int *index);
int					handle_dollar_int(t_expanded **expanded_list, int *index);
char				*handle_dollar_int_expanded(void);
int 				handle_dollar_name(t_exp_arg exp_arg, int i,
						t_expanded **expanded_list, int *index);
void				handle_dollar_number(char *str, t_expanded **expanded_list,
						int *index, int i);
char				*insert_expansions(int full_size, t_expanded *expanded_list,
						char *str);
int					is_operator_in_expansion(char c);
int					is_varname(char c);
char				*malloc_varname(char *str, int start, int end);
int					nothing_follows_follar(char *str, int i);
void				print_dollar_lst(t_expanded *lst);
void				print_tab(int *tab, int n);
char				*remove_dollars( char *str);
int					count_my_dollars(char *str);
int					count_dollars_in_str(char *str);
int					same_with_brackets_number(char *str, int i);
int					same_with_brackets_zero(char *str, int i);
int					*save_operator_index(char *str, char *new_str, t_expanded *expanded_list);
//do
int					do_builtin(t_ulist **cmd_lst, t_cmd *cmd);
void				do_builtin_close_fd(void *content);
int					do_builtin_dup_fd_in(t_cmd *cmd);
int					do_builtin_dup_fd_out(t_cmd *cmd);
int					do_builtin_exit(int err_no);

void				pipe_cmd_dup_fd_in(t_ulist **cmd_lst, t_cmd *cmd);
void				pipe_cmd_dup_fd_out(t_ulist **cmd_lst, t_cmd *cmd);

//do_cd
int					do_cd(t_ulist **envp, t_cmd *cmd);
int					do_cd_change_dir(t_ulist **envp, t_cmd *cmd);
int					do_cd_home(t_ulist **envp);
int					do_cd_update_env(t_ulist *obj, char *path);
int					do_cd_update_pwd_change_dir(t_ulist **envp, char *pwd);
int					do_cd_update_pwd_home(t_ulist **envp, t_ulist *obj,
						char *pwd);

//do_echo
int					do_echo_get_index(t_list *token_list);
int					do_echo(t_cmd *cmd);
int					do_echo_get_index(t_list *token_list);
int					do_echo_n(t_cmd *cmd, int index);
int					do_echo_valid_echo_n(t_list *token_list);

//do_env
int					do_env(t_ulist **envp, t_cmd *cmd);
void				do_env_show(void *content);

//do_exit
int					do_exit(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd);
void				do_exit_clear(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd, char *err_msg);

//do_export
int					do_export(t_ulist **env_lst, t_cmd *cmd);
int					do_export_create_env(t_ulist **list, char *str);
t_ulist				*do_export_check_exist(t_ulist **env_lst, char *str,
						int sep_pos);
size_t					do_export_check_exist_len_key(char *str,
						int sep_pos);
int					do_export_check_str(char *str, int sep_pos);
int					do_export_update_env(t_ulist *obj, char *str, int sep_pos);
int					do_export_update_lst(t_ulist **env_lst, char **str);
int					do_export_update_lst_do(t_ulist **env_lst, t_ulist *obj, char *str, int sep_pos);
void				do_export_show(void *content);

//do_pwd
int					do_pwd(t_cmd *cmd);
int     				do_pwd_check_str(char *str);
char				*do_pwd_getpath(void);
int     				do_pwd_loop_arg(char **str);

//do_unset
int					do_unset(t_ulist **envp, t_cmd *cmd);
int					do_unset_check_str(char *str);
int					do_unset_update_lst(t_ulist **envp, char **str);

//tokenizer
void				concatenate_export_args(t_list **token_list);
void				delete_content(t_list *token_list);
void				delete_spaces(t_list **token_list);
int					seen_equal_last(char *token);
void				tokenize(t_chartype *input_list, t_list **token_list, int *tab);
char 				*trim_quotes(char *str);
char 				*trim_quotes_token(char *str);

//give_chartype
int					get_chartype(t_chartype **input_list, int *tab);
int					is_char_space(char c);
int					is_char_word(char c);

//give_type_to_token
int					arg_dlredir_sep_token(t_list **token_list);
int					cmd_heredoc(t_list **token_list);
int					cmd_redir(t_list **token_list);
int					combo_heredoc_when_heredoc_index_zero(t_list **token_list);
int					combo_is_after_pipe(t_list **token_list);
int					combo_is_at_the_beggining(t_list **token_list);
int					following_pipe(t_list **token_list);
void				get_toktype(t_list **token_list);
int					heredoc_combo_is_at_the_beggining(t_list **token_list);
int					heredoc_combo_is_after_pipe(t_list **token_list);
int					is_argument(t_list **token_list);
int					is_built_in(t_list **token_list);
int					is_cmd(t_list **token_list);
int					is_combo_heredoc(t_list **token_list);
int					is_combo_redir(t_list **token_list);
int					is_combo_redir_when_redir_index_zero(t_list **token_list);
int					is_filename(t_list **token_list);
int					is_heredoc_sep(t_list **token_list);
t_toktype			is_operator(char *str);
int					only_space_in_str(char *str);
int					pipe_cmd_dlredir_sep_token(t_list **token_list);
int					not_operator(t_list *token_list);
int					redir_space_token(t_list **token_list);
int					redir_token(t_list **token_list);
int					start_cmd_dlredir_sep_token(t_list **token_list);
int					token_space_redir(t_list **token_list);
int					token_redir(t_list **token_list);
int					heredoc_combo_is_at_the_beggining(t_list **token_list);
int					heredoc_combo_is_after_pipe(t_list **token_list);

//make_token
void				add_token_to_list(char *token, t_list **token_list);
void				built_echo(t_list **token_list, int space);
void				built_token(t_chartype *input_list, int start, int end,
						t_list **token_list);
void				check_operator_presence(char *token, t_list **token_list);
int					count_d_quotes(t_chartype *input_list, int end);
int					count_s_quotes(t_chartype *input_list, int end);
int					echo_n(t_chartype *input_list, int *end, int *quote);
void				echo_special_treatment(t_chartype *input_list,
						int *end, int *space, int *quote);
int					empty_string(t_chartype *input_list, int end);
void				move_while_inside_quote(t_chartype *input_list, int *end, int s, int d);
int					not_only_space_between_quotes(char *str);
void				get_token(t_chartype *input_list, t_list **token_list);
void				is_bn(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_quote(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_dl_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_dr_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
int					is_heredoc_separator(t_list *token_list);
void				is_intpoint(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_l_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_pipe(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_r_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_space(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_word(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
int					no_space_inside_quotes(t_chartype *input_list, int end, int quote);

int					space_after_quote(t_chartype *input_list, int end, int quote);


//signal_handling
int					sig_hd_set_action(void);
void				sig_hd_sigint(int signum);
int					sig_hd_unset_action(void);
void				sig_pipe_quit(int signum);
int					sig_pipe_set_action(void);
void				sig_program_prompt_back(int signum);
int					sig_program_set_action(void);
int					sig_program_unset_action(void);

//environment list
int					env_char_env(t_env *env, char **envp,
						int i);
char				**env_char_init(size_t len_env_lst);
int					env_char_loop_env_lst(t_ulist *obj,
						char **envp);
char				**env_char_set(t_ulist **env_lst);
size_t				env_char_size(t_ulist **env_lst);
void				env_free(void *content);
t_env				*env_init(char *env_fullname);
char				*env_init_key(t_env *env, char *fullname);
int					env_init_value(t_env *env,
						char *fullname);
int					env_init_var_view(t_env *env);
int					env_lst_set(char **envp, t_ulist **env_lst);
void				env_lst_show(t_ulist **list);
void				env_show(void *content);

//command list
int					cmd_check_tok_lst(t_list **tok_lst);
int					cmd_check_tok_lst_hd(t_list *tok);
int					cmd_check_tok_lst_redir(t_list *tok);
int					cmd_create_lst(t_list **tok_lst, t_ulist **env_lst,
						t_ulist **cmd_lst);
int					cmd_exec(t_ulist **cmd_lst, int n_cmd);
int					cmd_exec_only_builtin(t_ulist **cmd_lst, t_cmd *cmd);
void				cmd_free(void *content);
char				*cmd_getvalidpath(t_cmd *cmd);
char				*cmd_getvalidpath_null(t_cmd *cmd);
t_cmd				*cmd_init(t_list **tok_lst, t_ulist **env_lst);
t_list				*cmd_init_prop(t_list *tok, t_cmd *cmd);
t_list				*cmd_init_prop_fullcmd(t_list *tok, t_cmd *cmd);
t_list				*cmd_init_prop_fullcmd_null(t_list *tok, t_cmd *cmd);
int					cmd_init_prop_fullpath(t_cmd *cmd);
size_t				cmd_init_prop_n_arg(t_list *tok);
char				*cmd_loop_envline(char *cmd, char **envline);
char				*cmd_loop_envp(char *cmd, t_ulist **envp_lst);
char				*cmd_loop_envp_str(char *cmd, t_ulist **envp_lst, char *s);
char				**cmd_loop_envp_create_envline(t_env *envp);
char				*cmd_setpath(char *cmd, char *env);
void				cmd_show(void *content);

//file_descriptor
int					fd_access(char *fd, int mode);
int					fd_close(t_cmd *cmd);
int					fd_hd_open(t_cmd *cmd);
int					fd_infile_open(t_cmd *cmd, char *fd, int mode);
void				fd_link_in_out_file(t_list **tok_lst, t_ulist **cmd_lst,
						int mode);
t_list				*fd_loop_tok(t_list *tok, t_cmd *cmd, int mode);
void				fd_loop_tok_secure(t_cmd *cmd, int res_loop);
int					fd_loop_tok_type(t_list *tok, t_cmd *cmd,
						enum e_toktype toktype, int mode);
int					fd_open(char *fd, int mode);
int					fd_outfile_open(t_cmd *cmd, char *fd, int mode);
void				fd_pipe(t_ulist **cmd_lst);
void				fd_pipe_pfd(t_ulist *obj, t_cmd *cmd1, t_cmd *cmd2,
						int n_pipe);
int					fd_stdinout_backup(int *fd_stdin, int *fd_stdout);
void				fd_stdinout_backup_close(int fd_stdin, int fd_stdout);
int					fd_stdinout_restore(t_cmd *cmd, int fd_stdin, int fd_stdout);

//heredoc
char				*expand_dollar_heredoc(t_exp_arg exp_arg);
void				find_expansions_heredoc(t_exp_arg exp_arg, t_expanded **expanded_list,
						int *full_size);
void				get_expanded_heredoc(t_exp_arg exp_arg, t_expanded **expanded_list,
						int i, int *varsize);
int					hd_close(t_cmd *cmd);
char				*hd_create_name(t_list *tok, t_cmd *cmd);
void				hd_create_name_len(char *index, size_t *len_index, size_t *len_smb, size_t *len_tmp);
void				hd_create_name_reset(t_cmd *cmd);
int					hd_init(t_list *tok, t_cmd *cmd, long long *hd_exit);
int					hd_init_check_binary(void);
int					hd_init_check_tmp(void);
int					hd_link(t_list **tok_lst, t_ulist **cmd_lst);
t_list				*hd_loop_tok(t_list *tok, t_cmd *cmd, long long *hd_exit);
int					hd_open(t_cmd *cmd);
size_t				hd_size(t_list **tok_lst);
int					hd_wait(int pid, long long *hd_exit);
void				hd_write(t_list *tok, t_cmd *cmd);
char				*hd_write_expansion(char *str, t_ulist **envp);
int					hd_write_mode(t_list *tok);
void				hd_write_str(t_list *tok, t_cmd *cmd, char **fullcmd, int mode);
char				*insert_expansions_heredoc(int full_size, t_expanded *expanded_list,
						char *str);

//pipe
void				pipe_close_pfd(void *content);
void				pipe_cmd(t_ulist **cmd_lst, t_ulist *obj);
void				pipe_cmd_dup_fd_in(t_ulist **cmd_lst, t_cmd *cmd);
void				pipe_cmd_dup_fd_out(t_ulist **cmd_lst, t_cmd *cmd);
void				pipe_cmd_end(t_ulist **cmd_lst, t_cmd *cmd, int err_no, char **envp);
void				pipe_exit(t_ulist **cmd_lst, t_cmd *cmd, int err_no);
int					pipe_run(t_ulist **cmd_lst, int n_cmd);
int					pipe_run_end(t_ulist **cmd_lst, int n_cmd, pid_t pid, int res);
int					pipe_wait(int n_cmd, int pid);
int					pipe_wait_check_child(int status);
int					pipe_wait_check_last(int status);
int					pipe_wait_return(int status_last, int res_last, int res_child);

//TEST
void				test_antho(t_ulist **env_lst);

#endif

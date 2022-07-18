/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 15:31:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdint.h>
# include <sys/types.h>

# include "libft.h"

# define WRONG_CMD 127
# define MALLOC_FAILURE -42
# define MISSING_QUOTES -43
# define MISPLACED_PIPE -44
# define MISPLACED_REDIR -45
# define BACK_SLASH -46
# define SEMICOLON -47
# define DOUBLE_PIPE -48
# define MISSING_BRACKET -49
	
# define ARG_SEP ' '
# define DIR_SEP "/"
# define ENV_SEP '='
# define ENV_FIELD_SEP ':'
# define EXP_PREFIX "declare -x "

# define ENV_HOME_NAME "HOME"
# define ENV_OLDPWD_NAME "OLDPWD"
# define ENV_PATH_NAME "PATH"
# define ENV_PWD_NAME "PWD"

# define ERR_EXP_ARG "not a valid identifier"
# define ERR_NOHOME "HOME not set"
# define ERR_UNSET_ARG "not a valid identifier"

typedef enum enum_chartype {
	CH_UNKNOWN,
	CH_WORD,
	CH_SPACE,
	CH_PIPE,
	CH_S_QUOTE,
	CH_D_QUOTE,
	CH_DOLLAR,
	CH_L_REDIR,
	CH_R_REDIR,
	CH_EQUAL,
	CH_INTPOINT,
	CH_BN,
}	t_enum_chartype;

typedef struct s_chartype {
	char			character;
	int				length;
	int				n_double;
	int				n_single;
	t_enum_chartype	type;
}	t_chartype;

typedef struct s_global {
	int			readline;
}	t_global;

typedef struct s_cursor {
	int			i;
	int			k;
}	t_cursor;

typedef struct s_expanded {
	int					index;
	char				*expanded;
	struct s_expanded	*prev;
	struct s_expanded	*next;
}	t_expanded;

typedef enum e_var_view
{
	VAR_ALL,
	VAR_ENV,
	VAR_EXP
} e_var_view;

typedef struct s_env {
	char		*key;
	char		*value;
	e_var_view	var_view;
}	t_env;

typedef struct s_cmd
{
	t_ulist	**env_lst;
	e_toktype	toktype;
	char	*arg;
	size_t	n_arg;
	char	**fullcmd;
	char	*fullpath;
	int		fd_r;
	int		fd_w;
	int		access;
}		t_cmd;

//input_handler
int					get_input(int *err);
void				read_line(char **str);
void				exit_minishell(t_list **token_list, int *err);
void				handle_str(char **str, t_list **token_list, int *err);
int					get_input(int *err);

//parsing
int					ft_parse(char *str, t_list **token_list, int *err);
void				create_input_list(t_chartype **input_list, char *str);
void				sort_inputs(char **inputs);
char				**store_built_ins(void);
t_list				*create_list(char *str, int i, e_toktype e_toktype);
void				print_lst(t_list *lst);
//void				ft_panic(int errcode, char *str);
int					handle_unknown_command(t_list *inputs_lst);
int					is_not_clone(char *str);
int					is_not_empty(char *str);
void				count_quotes(char *str, t_chartype *input_list);
int					count_double(char *str);
int					count_single(char *str);

//lexer
int					pre_lexer(char *str, int *err);
int					lex_pipe(char *str, int *err);
int					lex_quote(char *str, int *err);
int					lex_redir(char *str, int *err);
int					lex_sym(char *str, int *err);
int					lex_brackets(char *str, int *err);
int					lex_space(char *str, int *err);

//expansions
char				*expand_dollar(char *str);
void				find_expansions(char *str, t_expanded **expanded_list,
						int *full_size);
char				*insert_expansions(int full_size, t_expanded *expanded_list,
						char *str, int lb);
int					get_full_size(t_expanded *expanded_list);
void				get_expanded(char *str, t_expanded **expanded_list, int i,
						int *varsize);
char				*malloc_varname(char *str, int start, int end);
t_expanded			*create_dollar_list(char *str, int index);
t_expanded			*ft_lstnew_dollar(char *str, int i);
void				ft_lstadd_back_dollar(t_expanded **alst, t_expanded *new);
int					is_varname(char c);
void				print_dollar_lst(t_expanded *lst);
void				ft_lstclear_back_dollar(t_expanded **lst);
void				ft_lstclear_dollar(t_expanded **lst);
char				*expand_dollar(char *str);
int					lonely_bracket(char *str);

//built-in
int					do_echo(char *str);
int					do_echo_n(char *str);
int					do_pwd(void);

//do_cd
int					do_cd(t_ulist **envp, t_cmd *cmd);
int					do_cd_home(t_ulist **envp);
int					do_cd_update_home(t_ulist **envp, t_ulist *obj);

//do_env
int					do_env(t_ulist **envp, t_cmd *cmd);
void				do_env_show(void *content);

//do_unset
int	do_unset(t_ulist **envp, t_cmd *cmd);
int	do_unset_check_str(char *str);
int     do_unset_update_lst(t_ulist **envp, char **str);

//do_exit
void				do_exit(int exit_number);

//do_export
int				do_export(t_ulist **env_lst, t_cmd *cmd);
int				do_export_create_env(t_ulist **list, char *str);
t_ulist	*do_export_check_exist(t_ulist **envp, char *str, int sep_pos);
int				do_export_check_str(char *str);
int				do_export_update_env(t_ulist *obj, char *str, int sep_pos);
int				do_export_update_lst(t_ulist **envp, char **str);
void				do_export_show(void *content);

//execute_command
int					read_command(t_list *inputs_lst, char **built_ins);
int					execute_command(char *str, int i);

//tokenizer
void				tokenize(t_chartype *input_list, t_list **token_list);

//give_chartype
int					get_chartype(t_chartype **input_list);
int					is_char_space(char c);
int					is_char_word(char c);

//give_type_to_token
int					cmd_heredoc(t_list **token_list);
int					cmd_redir(t_list **token_list);
int					combo_is_after_pipe(t_list **token_list);
int					combo_is_at_the_beggining(t_list **token_list);
int					following_pipe(t_list **token_list);
void				get_toktype(t_list **token_list);
int					is_argument(t_list **token_list);
int					is_built_in(t_list **token_list);
int					is_cmd(t_list **token_list);
int					is_combo_heredoc(t_list **token_list);
int					is_combo_redir_when_redir_index_zero(t_list **token_list);
int					is_combo_redir(t_list **token_list);
int					is_filename(t_list **token_list);
int					is_heredoc_sep(t_list **token_list);
e_toktype			is_operator(char *str);
int					only_space_in_str(char *str);
int					redir_space_token(t_list **token_list);
int					redir_token(t_list **token_list);
int					token_space_redir(t_list **token_list);
int					token_redir(t_list **token_list);

int					is_combo_heredoc_when_heredoc_index_zero(t_list **token_list);
int					heredoc_combo_is_at_the_beggining(t_list **token_list);
int					heredoc_combo_is_after_pipe(t_list **token_list);

//make_token
void				add_token_to_list(char *token, t_list **token_list);
void				built_token(t_chartype *input_list, int start, int end,
						t_list **token_list);
void				get_token(t_chartype *input_list, t_list **token_list);
void				is_bn(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_d_quote(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_dl_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_dr_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_intpoint(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_l_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_pipe(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_r_redir(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_s_quote(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_space(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				is_word(t_chartype *input_list, int *start, int *end,
						t_list **token_list);
void				remove_quotes(t_chartype *input_list, int *start, int *end);
void				remove_dquotes(t_chartype *input_list, int *start,
						int *end);
void				remove_squotes(t_chartype *input_list, int *start,
						int *end);

//signal_handling
int					ft_set_sigaction(void);
void				give_prompt_back(int signum);

//environment list
void    env_free(void *content);
t_env   *env_init(char *env_fullname);
char    *env_init_key(t_env *env, char *fullname);
int	env_init_value(t_env *env, char *fullname);
int	env_init_var_view(t_env *env);
int     env_lst_set(char **envp, t_ulist **env_lst);
void    env_lst_show(t_ulist **list);
void    env_show(void *content);

//command list
void    cmd_close_fd(void *content);
int     cmd_create_lst(t_list *tok, t_ulist **env_lst, t_ulist **cmd_lst);
void    cmd_free(void *content);
char	*cmd_getvalidpath(t_cmd *cmd);
char	*cmd_getvalidpath_null(t_cmd *cmd);
t_cmd   *cmd_init(t_ulist **env_lst);
t_list	*cmd_init_prop(t_list *tok, t_cmd *cmd);
t_list	*cmd_init_prop_fullcmd(t_list *tok, t_cmd *cmd);
t_list	*cmd_init_prop_fullcmd_null(t_list *tok, t_cmd *cmd);
size_t	cmd_init_prop_n_arg(t_list *tok, t_cmd *cmd);
char	*cmd_loop_envline(char *cmd, char **envline);
char	*cmd_loop_envp(char *cmd, t_ulist **envp_lst);
char	*cmd_loop_envp_str(char *cmd, t_ulist **envp_lst, char *s);
char	*cmd_setpath(char *cmd, char *env);
void	cmd_show(void *content);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/11 13:51:38 by abarrier         ###   ########.fr       */
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

# define ENV_SEP '='
# define ENV_FIELD_SEP ':'
# define ENV_PATH_NAME "PATH="
# define DIR_SEP "/"
# define ARG_SEP ' '

typedef enum e_chartype {
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
} e_chartype;

typedef struct s_chartype {
	char		character;
	int			length;
	int			n_double;
	int			n_single;
	e_chartype	type;
} t_chartype;

typedef struct s_global {
	int			readline;
} t_global;

typedef struct s_expanded {
	int					index;
	char 				*expanded;
	struct s_expanded	*prev;
	struct s_expanded	*next;
} t_expanded;

typedef struct s_env {
	char	*fullname;
	char	*key;
	char	*value;
	char	*old_fullname;
	char	*old_value;
	int	is_new;
}	t_env;

typedef struct s_cmd
{
	t_ulist	**env_lst;
	char	*arg;
	char	**fullcmd;
	char	*fullpath;
	int		fd_r;
	int		fd_w;
	int		access;
}		t_cmd;

//main.c
//int					main(void);
int					get_input(void);

//parsing
int					ft_parse(char *str, t_list **token_list);
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
int					pre_lexer(char *str);
int					lex_pipe(char *str, int *err);
int					lex_quote(char *str, int *err);
int					lex_redir(char *str, int *err);
int					lex_sym(char *str, int *err);
//expansions
char				*expand_dollar(char *str);
void				find_expansions(char *str, t_expanded **expanded_list, int *full_size);
char				*insert_expansions(int full_size, t_expanded *expanded_list, char *str);
int					get_full_size(t_expanded *expanded_list);
void				get_expanded(char *str, t_expanded **expanded_list, int i, int *varsize);
char				*malloc_varname(char *str, int start, int end);
t_expanded			*create_dollar_list(char *str, int index);
t_expanded			*ft_lstnew_dollar(char *str, int i);
void				ft_lstadd_back_dollar(t_expanded **alst, t_expanded *new);
int 				is_varname(char c);
void				print_dollar_lst(t_expanded *lst);
void				ft_lstclear_back_dollar(t_expanded **lst);
void				ft_lstclear_dollar(t_expanded **lst);

//built-in
int					do_echo(char *str);
int					do_echo_n(char *str);
int					do_cd(char *str);
int					do_pwd(void);
int					do_export(char *str);

//do_env
int					do_env(t_ulist **envp, t_cmd *cmd);
int     do_env_create_env(t_ulist **list, char *str);
int     do_env_update_env(t_ulist *obj, char *str, int sep_pos);
int     do_env_update_lst(t_ulist **envp, char **str);
void				do_env_show(void *content);

//do_unset
int	do_unset(t_ulist **envp, t_cmd *cmd);
int     do_unset_update_lst(t_ulist **envp, char **str);

//do_exit
void				do_exit(int exit_number);

//execute_command
int					read_command(t_list *inputs_lst, char **built_ins);
int					execute_command(char *str, int i);

//tokenizer
void				tokenize(t_chartype *input_list, t_list **token_list);
int					get_chartype(t_chartype **input_list);
void				get_token(t_chartype *input_list, t_list **token_list);
void				built_token(t_chartype *input_list, int start, int end, t_list **token_list);
void				remove_quotes(t_chartype *input_list, int *start, int *end);
void				remove_dquotes(t_chartype *input_list, int *start, int *end);
void				remove_squotes(t_chartype *input_list, int *start, int *end);
void				add_token_to_list(char *token, t_list **token_list);
int					is_char_word(char c);
int					only_space_in_str(char *str);

//get_toktype
void				get_toktype(t_list **token_list);
int					is_char_space(char c);
e_toktype			is_operator(char *str);

// int					is_charword(char c);

// static int			is_char_word(char c);
void				is_word(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_space(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_pipe(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_s_quote(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_d_quote(t_chartype *input_list, int *start, int *end, t_list **token_list);
// t_list				*is_envcall(t_chartype *input_list, int *start, int *end);
void				is_l_redir(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_r_redir(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_dl_redir(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_dr_redir(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_bn(t_chartype *input_list, int *start, int *end, t_list **token_list);
void				is_intpoint(t_chartype *input_list, int *start, int *end, t_list **token_list);

//signal_handling
int					ft_set_sigaction(void);
void				give_prompt_back(int signum);

//environment list
void    env_free(void *content);
t_env   *env_init(char *env_fullname);
char    *env_init_key(t_env *env, char *fullname);
char    *env_init_value(t_env *env);
int     env_lst_set(char **envp, t_ulist **env_lst);
void    env_lst_show(t_ulist **list);
void    env_show(void *content);

#endif

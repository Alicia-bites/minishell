/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 16:48:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdint.h>
#include <sys/types.h>

#include "../libft/libft.h"

#define WRONG_CMD 127
#define MALLOC_FAILURE -42
#define MISSING_QUOTES -43
#define MISPLACED_PIPE -44
#define MISPLACED_REDIR -45
#define BACK_SLASH -46
#define SEMICOLON -47
#define DOUBLE_PIPE -48

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

//main.c
//int					main(void);
int					main();
int					get_input(void);

//parsing
int					ft_parse(char *str, t_list **token_list);
void				create_input_list(t_chartype **input_list, char *str);
void				sort_inputs(char **inputs);
char				**store_built_ins(void);
t_list				*create_list(char *str, int i, e_toktype e_toktype);
void				print_lst(t_list *lst);
void				ft_panic(int errcode, char *str);
int					handle_unknown_command(t_list *inputs_lst);
int					is_not_clone(char *str);
int					is_not_empty(char *str);
void				count_quotes(char *str, t_chartype *input_list);
int					count_double(char *str);
int					count_single(char *str);

//lexer
int					lexer(char *str);
int					lex_pipe(char *str, int *err);
int					lex_quote(char *str, int *err);
int					lex_redir(char *str, int *err);
int					lex_sym(char *str, int *err);
//expansions
char				*expand_dollar(char *str, t_chartype *input_list);
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
int					do_unset(char *str);
int					do_env(char **envp);
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
void				get_toktype(t_chartype *input_list, t_list **token_list);
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

#endif

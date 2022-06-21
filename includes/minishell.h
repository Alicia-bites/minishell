/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 18:34:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../libft/libft.h"

#define MALLOC_FAILURE -42
#define WRONG_CMD 127

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
} e_chartype;

typedef struct s_chartype {
	char		character;
	int			length;
	int			n_double;
	int			n_single;
	e_chartype	type;
} t_chartype;


typedef struct s_global {
	int	list_cleared;
} t_global;


//main.c
int					main(void);
int					get_input(void);

//parsing
void				ft_parse(char *str, t_list **token_list);
void				sort_inputs(char **inputs);
char				**store_built_ins(void);
t_list				*create_list(char *str, int i, e_toktype e_toktype);
void				print_lst(t_list *lst);
void				ft_panic(int errcode, char *str);
int					handle_unknown_command(t_list *inputs_lst);
int					is_not_clone(char *str);
int					is_not_empty(char *str);
void				count_quotes(char *str, t_chartype *input_list);
//built-in
int					do_echo(char *str);
int					do_echo_n(char *str);
int					do_cd(char *str);
int					do_pwd(void);
int					do_export(char *str);
int					do_unset(char *str);
int					do_env(char *str);
int					do_exit();

//execute_command
int					read_command(t_list *inputs_lst, char **built_ins);
int					execute_command(char *str, int i);

//tokenizer
void				tokenize(t_chartype *input_list, t_list **token_list);
int					get_chartype(t_chartype **input_list);
// static void			print_chartype(t_chartype *input_list);
void				get_token(t_chartype *input_list, t_list **token_list);
int					is_charword(char c);
t_list				*built_token(t_chartype *input_list, int start, int end);
void				add_token_to_list(char *token, t_list **token_list);
// static int			is_char_word(char c);
t_list				*is_word(t_chartype *input_list, int *start, int *end);
t_list				*is_space(t_chartype *input_list, int *start, int *end);
t_list				*is_pipe(t_chartype *input_list, int *start, int *end);
t_list				*is_s_quote(t_chartype *input_list, int *start, int *end);
t_list				*is_d_quote(t_chartype *input_list, int *start, int *end);
// t_list				*is_envcall(t_chartype *input_list, int *start, int *end);
t_list				*is_l_redir(t_chartype *input_list, int *start, int *end);
t_list				*is_r_redir(t_chartype *input_list, int *start, int *end);
t_list				*is_dl_redir(t_chartype *input_list, int *start, int *end);
t_list				*is_dr_redir(t_chartype *input_list, int *start, int *end);
t_list				*is_intpoint(t_chartype *input_list, int *start, int *end);

#endif
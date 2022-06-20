/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 13:57:32 by amarchan         ###   ########.fr       */
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
	e_chartype	type;
} t_chartype;

//main.c
int					main(void);
int					get_input(void);

//parsing
char 				*ft_parse(char *str);
void				sort_inputs(char **inputs);
char				**store_built_ins(void);
t_list				*create_list(char *str, int i);
void				print_lst(t_list *lst);
void				ft_panic(int errcode, char *str);
int					handle_unknown_command(t_list *inputs_lst);

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
int					tokenize(t_chartype *input_list);
int					is_charword(char c);
#endif
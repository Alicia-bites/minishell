/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:28:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 09:10:21 by abarrier         ###   ########.fr       */
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

//main.c
//int					main(void);
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
int					do_env(char **envp);
void				do_exit(int exit_number);

//execute_command
int					read_command(t_list *inputs_lst, char **built_ins);
int					execute_command(char *str, int i);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:40:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(char *str, t_list **token_list, int *err, t_ulist *envp)
{
	char			*tmp;
	extern t_global	g_msl;
	t_chartype		*input_list;
	t_exp_arg		exp_arg;
	
	if (!only_space_in_str(str))
		return (*err);
	tmp = str;
	input_list = NULL;
	exp_arg.envp = envp;
	exp_arg.str = str;
	if (lexer(tmp, err))
		return (*err);
	if (ft_strstr(tmp, "$"))
		tmp = expand_dollar(exp_arg);
	create_input_list(&input_list, tmp);
	if (ft_strcmp(str, tmp))
		free(tmp);
	tokenize(input_list, token_list);
	free(input_list);
	return (*err);
}

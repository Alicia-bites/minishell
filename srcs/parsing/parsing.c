/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 16:40:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_up_input_and_tab(t_chartype **input_list, int **tab)
{
	if (*input_list)
		free(*input_list);
	if (*tab)
		free(*tab);
}

int	ft_parse(char *str, t_list **token_list, int *err, t_ulist *envp)
{
	char			*tmp;
	t_chartype		*input_list;
	t_exp_arg		exp_arg;
	t_tab			tab;

	tab.tab_op = NULL;
	tab.tab_quote = NULL;
	if (!only_space_in_str(str))
		return (*err);
	tmp = str;
	input_list = NULL;
	exp_arg.envp = envp;
	exp_arg.str = str;
	if (lexer(tmp, err))
		return (*err);
	if (ft_strstr(tmp, "$"))
		tmp = expand_dollar(exp_arg, &tab);
	if (!tmp)
		return (MALLOC_FAILURE);
	create_input_list(&input_list, tmp, &tab.tab_quote);
	if (ft_strcmp(str, tmp))
		free(tmp);
	tokenize(input_list, token_list, tab.tab_op);
	clean_up_input_and_tab(&input_list, &tab.tab_op);
	return (*err);
}

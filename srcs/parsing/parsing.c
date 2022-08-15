/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:57 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_up(t_chartype **input_list, int **tab)
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
	int				*tab;

	tab = NULL;
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
	create_input_list(&input_list, tmp);
	if (ft_strcmp(str, tmp))
		free(tmp);
	tokenize(input_list, token_list, tab);
	clean_up(&input_list, &tab);
	return (*err);
}

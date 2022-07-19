/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 15:34:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(char *str, t_list **token_list, int *err)
{
	char			*tmp;
	extern t_global	global;
	t_chartype		*input_list;

	tmp = str;
	input_list = NULL;
	global.ignore_op = 0;
	if (lexer(tmp, err))
		return (*err);
	if (ft_strstr(tmp, "$"))
		tmp = expand_dollar(str);
	create_input_list(&input_list, tmp);
	if (ft_strcmp(str, tmp))
		free(tmp);
	tokenize(input_list, token_list);
	free(input_list);
	return (*err);
}

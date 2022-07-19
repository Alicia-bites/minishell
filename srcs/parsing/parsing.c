/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 15:07:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(char *str, t_list **token_list, int *err)
{	
	t_chartype	*input_list;
	char		*tmp;

	tmp = str;
	input_list = NULL;
	if (pre_lexer(tmp, err))
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

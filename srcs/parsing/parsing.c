/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/13 14:29:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(char *str, t_list **token_list, int *err)
{	
	t_chartype	*input_list;

	input_list = NULL;
	if (pre_lexer(str, err))
		return (*err);
	if (ft_strstr(str, "$"))
		str = expand_dollar(str);
	if (pre_lexer(str, err))
		return (*err);
	create_input_list(&input_list, str);
	tokenize(input_list, token_list);
	free(input_list);
	return (0);
}

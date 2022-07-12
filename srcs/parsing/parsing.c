/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 17:56:04 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(char *str, t_list **token_list)
{	
	t_chartype	*input_list;
	int			err;

	err = 0;
	input_list = NULL;
	if (pre_lexer(str))
		return (err);	
	if (ft_strstr(str, "$"))
		str = expand_dollar(str);
	if (pre_lexer(str))
		return (err);
	create_input_list(&input_list, str);
	tokenize(input_list, token_list);
	free(input_list);
	return (0);
}

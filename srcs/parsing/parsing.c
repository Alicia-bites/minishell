/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/08 16:35:28 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_parse(char *str, t_list **token_list)
{	
	t_chartype	*input_list;
	int			err;

	if (pre_lexer(str))
		return (err);
	if (ft_strstr(str, "$") && (!count_single(str) || count_single(str) % 2))
		str = expand_dollar(str, input_list);
	if (pre_lexer(str))
		return (err);
	create_input_list(&input_list, str);
	tokenize(input_list, token_list);
	print_lst(*token_list);
	return (0);
}

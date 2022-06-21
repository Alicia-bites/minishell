/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_s_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:03 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 17:20:40 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*is_s_quote(t_chartype *input_list, int *start, int *end)
{
	t_list	*token_list;
	
	if (input_list[*end].type == CH_S_QUOTE)
	{
		(*end)++;
		if (input_list->n_single > 1)
		{
			while (input_list[*end].type == CH_WORD
				|| input_list[*end].type == CH_SPACE
				|| input_list[*end].type == CH_PIPE
				|| input_list[*end].type == CH_DOLLAR
				|| input_list[*end].type == CH_L_REDIR
				|| input_list[*end].type == CH_R_REDIR)
				(*end)++;
			input_list->n_single -= 2;
			(*end)++;
		}
		else if (input_list->n_single > 0)
		{
			while (input_list[*end].type == CH_WORD)
				(*end)++;
			input_list->n_single--;
		}
		token_list = built_token(input_list, *start, *end);
		*start = *end;
	}
	return (token_list);
}

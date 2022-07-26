/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_s_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:03 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/26 19:21:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_s_quote(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	if (*end > input_list->length)
		return ;
	if (input_list[*end].type == CH_S_QUOTE)
	{
		(*end)++;
		while (*end < input_list->length && input_list[*end].type != CH_S_QUOTE)
			(*end)++;
		if (*end < input_list->length)
			(*end)++;
		if (input_list[*end].type == CH_S_QUOTE)
			is_s_quote(input_list, start, end, token_list);
		else if (input_list[*end].type == CH_D_QUOTE)
			is_d_quote(input_list, start, end, token_list);			
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 09:01:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int	space;
	int	quote;

	space = 1;
	quote = 0;
	if (input_list[*end].type == CH_WORD)
	{
		while (*end < input_list->length
			&& input_list[*end].type == CH_WORD)
		{
			// if (echo_n(input_list, end, &quote))
			// {
			// 	echo_special_treatment(input_list, end, &space, &quote);
			// 	built_echo(token_list, space);
			// 	if (!space)
			// 	{
			// 		*start = *start + 5;
			// 		*end = *start;
			// 	}
			// 	else
			// 		*start = *end;
			// 	return ;
			// }
			if (*end + 1 > input_list->length)
				break ;
			(*end)++;
		}
		quote = *end;
		if (!empty_string(input_list, *end) && *end + 1 < input_list->length)
			is_quote(input_list, start, end, token_list);		
		if (quote == *end)
		{
			built_token(input_list, *start, *end, token_list);
			*start = *end;
		}
	}
}

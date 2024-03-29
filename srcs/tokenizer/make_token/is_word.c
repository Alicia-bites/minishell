/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 14:32:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int	quote;

	if (*end >= input_list->length)
		return ;
	quote = 0;
	if (input_list[*end].type == CH_WORD)
	{
		while (*end < input_list->length
			&& input_list[*end].type == CH_WORD)
		{
			if (*end + 1 > input_list->length)
				break ;
			(*end)++;
		}
		quote = *end;
		if (*end + 1 < input_list->length)
			is_quote(input_list, start, end, token_list);
		if (quote == *end)
		{
			built_token(input_list, *start, *end, token_list);
			*start = *end;
		}
	}
}

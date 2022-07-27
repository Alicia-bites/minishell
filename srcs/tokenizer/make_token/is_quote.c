/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:42 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 12:36:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// I browse through input_list with *end being my cursor, until I meet either
// way :
// 1. an operator outside of quotes,
// 2. a space outside of quotes.
void	move_while_inside_quote(t_chartype *input_list, int *end, int *quote)
{
	int	count_quote;

	count_quote = 0;
	while (*end < input_list->length)
	{
		while (input_list[*end].type == CH_S_QUOTE
			|| input_list[*end].type == CH_D_QUOTE)
		{
			count_quote++;
			(*end)++;			
		}
		if (count_quote == *quote
			&& (input_list[*end].type == CH_SPACE
				|| input_list[*end].type == CH_PIPE
				|| input_list[*end].type == CH_R_REDIR
				|| input_list[*end].type == CH_L_REDIR
				|| input_list[*end].character == '\0'))
				return ;
		(*end)++;
	}
}

void	is_quote(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{
	int	quote;
	int	count_quote;
	
	quote = 0;
	count_quote = 0;
	if (input_list[*end].type == CH_D_QUOTE
		|| input_list[*end].type == CH_S_QUOTE)
	{
		while (*end < input_list->length
		&& (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE))
		{
			(*end)++;
			quote++;
		}
		move_while_inside_quote(input_list, end, &quote);
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

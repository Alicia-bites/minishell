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
void	move_while_inside_quote(t_chartype *input_list, int *end, int s, int d)
{
	int	count_d;
	int count_s;

	count_d = 0;
	count_s = 0;
	while (*end < input_list->length)
	{
		while (*end < input_list->length
			&& input_list[*end].type == CH_S_QUOTE)
		{
			count_s++;
			(*end)++;			
		}
		while (*end < input_list->length
			&& input_list[*end].type == CH_D_QUOTE)
		{
			count_d++;
			(*end)++;			
		}
		// printf("d = %d\n", d);
		// printf("count_d = %d\n", count_d);
		// printf("s = %d\n", s);
		// printf("count_s = %d\n", count_s);
		if ((count_d >= d && count_s >= s)
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
	int d;
	int s;

	d = 0;
	s = 0;
	if (input_list[*end].type == CH_D_QUOTE
		|| input_list[*end].type == CH_S_QUOTE)
	{
		if (empty_string(input_list, *end))
		{
			*end += 2;
			*start = *end;
			return ;
		}
		while (*end < input_list->length
		&& input_list[*end].type == CH_D_QUOTE)
		{
			(*end)++;
			d++;
		}
		while (*end < input_list->length
		&& input_list[*end].type == CH_S_QUOTE)
		{
			(*end)++;
			s++;
		}
		move_while_inside_quote(input_list, end, s, d);
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

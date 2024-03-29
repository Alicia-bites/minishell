/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:08:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 18:50:45 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// I browse through input_list with *end being my cursor, until I meet either
// way :
// 1. an operator outside of quotes,
// 2. a space outside of quotes.
void	move_while_inside_quote(t_chartype *input_list, int *end, int s, int d)
{
	while (*end < input_list->length)
	{
		while (input_list[*end].type == CH_S_QUOTE
			|| input_list[*end].type == CH_D_QUOTE)
		{
			while (*end < input_list->length
				&& input_list[*end].type == CH_S_QUOTE)
				move_s_and_end(&s, end, d);
			while (*end < input_list->length
				&& input_list[*end].type == CH_D_QUOTE)
				move_d_and_end(&d, end, s);
		}	
		if (((!(s % 2) && !(d % 2))
				|| (!s && !d))
			&& (input_list[*end].type == CH_PIPE
				|| input_list[*end].type == CH_SPACE
				|| input_list[*end].type == CH_R_REDIR
				|| input_list[*end].type == CH_L_REDIR
				|| input_list[*end].character == '\0'))
			return ;
		(*end)++;
	}
}

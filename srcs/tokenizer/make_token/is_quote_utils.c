/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:08:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 19:56:16 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	count_d_quotes(t_chartype *input_list, int end)
// {
// 	int	d;

// 	d = 0;
// 	while (end < input_list->length
// 		&& (input_list[end].type != CH_PIPE
// 			|| input_list[end].type != CH_SPACE
// 			|| input_list[end].type != CH_R_REDIR
// 			|| input_list[end].type != CH_L_REDIR
// 			|| input_list[end].character != '\0'))
// 	{
// 		if (input_list[end].type == CH_D_QUOTE)
// 		{
// 			d++;
// 			if (end + 1 < input_list->length)
// 				end++;
// 			while (end < input_list->length
// 				&& input_list[end].type != CH_D_QUOTE)
// 					end++;
// 			if (input_list[end].type == CH_D_QUOTE)
// 				d++;
// 		}
// 		end++;
// 	}
// 	return (d);
// }

// int	count_s_quotes(t_chartype *input_list, int end)
// {
// 	int	s;

// 	s = 0;
// 	while (end < input_list->length
// 		&& (input_list[end].type != CH_PIPE
// 			|| input_list[end].type != CH_SPACE
// 			|| input_list[end].type != CH_R_REDIR
// 			|| input_list[end].type != CH_L_REDIR
// 			|| input_list[end].character != '\0'))
// 	{
// 		if (input_list[end].type == CH_S_QUOTE)
// 		{
// 			s++;
// 			if (end + 1 < input_list->length)
// 				end++;
// 			while (end < input_list->length
// 				&& input_list[end].type != CH_S_QUOTE)
// 					end++;
// 			if (input_list[end].type == CH_S_QUOTE)
// 				s++;
// 		}
// 		end++;
// 	}
// 	return (s);
// }

static void	move_count_s_and_end(int *count_s, int *end)
{
	(*count_s)++;
	(*end)++;
}

static void	move_count_d_and_end(int *count_d, int *end)
{
	(*count_d)++;
	(*end)++;
}

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
				move_count_s_and_end(&s, end);
			while (*end < input_list->length
				&& input_list[*end].type == CH_D_QUOTE)
				move_count_d_and_end(&d, end);
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

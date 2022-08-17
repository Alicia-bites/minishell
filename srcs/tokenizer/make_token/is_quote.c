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

static void	move_s_and_end(int *s, int *end)
{
	(*s)++;
	(*end)++;
}

static void	move_d_and_end(int *d, int *end)
{
	(*d)++;
	(*end)++;
}

void	is_quote(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{
	int	d;
	int	s;

	if (*end >= input_list->length)
		return ;
	d = 0;
	s = 0;
	if (input_list[*end].type == CH_D_QUOTE
		|| input_list[*end].type == CH_S_QUOTE)
	{
		while (empty_string(input_list, *end))
			*end += 2;
		while (*end < input_list->length
			&& input_list[*end].type == CH_D_QUOTE)
			move_d_and_end(&d, end);
		while (*end < input_list->length
			&& input_list[*end].type == CH_S_QUOTE)
			move_s_and_end(&s, end);
		move_while_inside_quote(input_list, end, s, d);
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

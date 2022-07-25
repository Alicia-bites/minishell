/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_d_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:42 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 18:21:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_d_quote(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{
	if (input_list[*end].type == CH_D_QUOTE)
	{
		(*end)++;
		if (input_list->n_double > 1)
		{
			while (input_list[*end].type != CH_D_QUOTE)
				(*end)++;
			input_list->n_double -= 2;
			(*end)++;
		}
		else if (input_list->n_double > 0)
		{
			while (input_list[*end].type == CH_WORD)
				(*end)++;
			input_list->n_double--;
		}
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

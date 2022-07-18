/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_intpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:53 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 17:18:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_intpoint(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{

	if (input_list[*end].type == CH_DOLLAR
		&& input_list[*end + 1].type == CH_INTPOINT)
	{
		(*end) += 2;
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
	
	else if (input_list[*end].type == CH_INTPOINT)
	{
		(*end)++;
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

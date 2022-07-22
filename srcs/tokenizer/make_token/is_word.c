/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 14:35:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int space;

	space = 1;
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (echo_n(input_list, end))
			{
				echo_special_treatment(input_list, end, &space);
				built_echo(token_list, space);
				if (!space)
				{
					*start = *start + 5;
					*end = *start;					
				}
				else
					*start = *end;
				return ;
			}
			(*end)++;
		}
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

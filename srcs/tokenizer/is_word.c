/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/25 19:04:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*is_word(t_chartype *input_list, int *start, int *end)
{
	t_list	*token_list;
	
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (input_list[*end + 1].type == CH_SPACE
				&& input_list[*end + 2].character == '-'
				&& input_list[*end + 3].character == 'n')
					(*end) += 3;
			(*end)++;			
		}
		token_list = built_token(input_list, *start, *end);
		*start = *end;
	}
	return (token_list);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 14:32:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_space(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	if (*end >= input_list->length)
		return ;
	if (input_list[*end].type == CH_SPACE)
	{
		while (input_list[*end].type == CH_SPACE)
			(*end)++;
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

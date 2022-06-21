/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 17:19:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list *is_pipe(t_chartype *input_list, int *start, int *end)
{
	t_list	*token_list;

	if (input_list[*end].type == CH_PIPE)
	{
		(*end)++;
		token_list = built_token(input_list, *start, *end);
		*start = *end;
	}
	return (token_list);
}

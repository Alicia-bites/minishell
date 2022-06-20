/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_s_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:03 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 18:17:56 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_s_quote(t_chartype *input_list, int *start, int *end)
{
	if (input_list[*end].type == CH_S_QUOTE)
	{
		(*end)++;
		built_token(input_list, *start, *end);
		*start = *end;
	}
}

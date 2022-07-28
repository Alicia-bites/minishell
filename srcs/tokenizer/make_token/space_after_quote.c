/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_after_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:12:09 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 19:12:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if after closing the last closing quote, you have a space. If so,
// you have a valid 'echo -n' combination. If something else than a space is
// found, return 0.
int	space_after_quote(t_chartype *input_list, int end, int quote)
{
	int	count_quote;

	count_quote = 0;
	while (end < input_list->length
		&& count_quote <= quote
		&& (input_list[end].type == CH_S_QUOTE
		|| input_list[end].type == CH_D_QUOTE))
		{
			end++;
			count_quote++;
		}
	if (input_list[end].type == CH_SPACE)
			return (1);
	else
		return (0);
}

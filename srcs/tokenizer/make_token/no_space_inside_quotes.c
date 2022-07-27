/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_space_inside_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:13:00 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 19:13:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// If between quotes,
// if space is found after n (no matter how many),
// return 0 --> not a valid '-n'
// If not between quotes, just return 1.
int	no_space_inside_quotes(t_chartype *input_list, int end, int quote)
{
	// printf("quote = %d\n", quote);
	if (quote)
	{
		if (input_list[end].type == CH_D_QUOTE
			|| input_list[end].type == CH_S_QUOTE)
				return (1);
		else
			return (0);
	}
	return (1);
}

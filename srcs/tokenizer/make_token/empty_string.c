/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:10:56 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:42:40 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	empty_string(t_chartype *input_list, int end)
{
	if (end + 1 < input_list->length
		&& ((input_list[end].type == CH_S_QUOTE
				&& input_list[end + 1].type == CH_S_QUOTE)
			|| (input_list[end].type == CH_D_QUOTE
				&& input_list[end + 1].type == CH_D_QUOTE)))
		return (1);
	return (0);
}

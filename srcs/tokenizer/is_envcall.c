/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_envcall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 15:55:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_envcall(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{
	if (input_list[*end].type == CH_DOLLAR
		&& input_list[*end + 1].type == CH_WORD)
	{
		*end += 1;
		while (input_list[*end].type == CH_WORD)
			(*end)++;
		built_token(input_list, *start, *end);
		*start = *end;
	}
}

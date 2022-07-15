/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 17:18:20 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_bn(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{

	if (input_list[*end].type == CH_BN)
	{
		while (input_list[*end].type == CH_BN)
			(*end)++;
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}
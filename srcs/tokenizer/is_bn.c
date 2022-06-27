/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/24 17:24:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*is_bn(t_chartype *input_list, int *start, int *end)
{
	t_list	*token_list;
	
	if (input_list[*end].type == CH_BN)
	{
		while (input_list[*end].type == CH_BN)
			(*end)++;
		token_list = built_token(input_list, *start, *end);
		*start = *end;
	}
	return (token_list);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 17:20:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*is_space(t_chartype *input_list, int *start, int *end)
{
	t_list	*token_list;
	
	if (input_list[*end].type == CH_SPACE)
	{
		while (input_list[*end].type == CH_SPACE)
			(*end)++;
		token_list = built_token(input_list, *start, *end);
		*start = *end;
	}
	return (token_list);
}

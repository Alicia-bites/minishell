/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 18:18:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_space(t_chartype *input_list, int *start, int *end)
{
	if (input_list[*end].type == CH_SPACE)
	{
		while (input_list[*end].type == CH_SPACE)
			(*end)++;
		built_token(input_list, *start, *end);
		*start = *end;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 18:17:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_pipe(t_chartype *input_list, int *start, int *end)
{
	if (input_list[*end].type == CH_PIPE)
	{
		(*end)++;
		built_token(input_list, *start, *end);
		*start = *end;
	}
}

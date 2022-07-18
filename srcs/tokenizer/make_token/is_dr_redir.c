/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dr_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 17:17:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_dr_redir(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{
	if (input_list[*end].type == CH_R_REDIR
		&& input_list[*end + 1].type == CH_R_REDIR)
	{
		(*end) += 2;
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

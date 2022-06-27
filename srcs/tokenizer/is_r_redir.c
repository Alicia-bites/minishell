/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_r_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 15:58:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*is_r_redir(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{
	if (input_list[*end].type == CH_R_REDIR
		&& input_list[*end + 1].type != CH_R_REDIR)
	{
		(*end)++;
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

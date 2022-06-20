/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dl_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:46 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 18:16:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_dl_redir(t_chartype *input_list, int *start, int *end)
{
	if (input_list[*end].type == CH_L_REDIR
		&& input_list[*end + 1].type == CH_L_REDIR)
	{
		(*end) += 2;
		built_token(input_list, *start, *end);
		*start = *end;
	}
}

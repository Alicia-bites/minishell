/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_l_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:56 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 17:19:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*is_l_redir(t_chartype *input_list, int *start, int *end)
{
	t_list	*token_list;

	if (input_list[*end].type == CH_L_REDIR
		&& input_list[*end + 1].type != CH_L_REDIR)
	{
		(*end)++;
		token_list = built_token(input_list, *start, *end);
		*start = *end;
	}
	return (token_list);
}

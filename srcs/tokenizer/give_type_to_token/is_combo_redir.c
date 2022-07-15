/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 09:49:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_combo_redir(t_list **token_list)
{
	if ((*token_list)->index >= 4)
	{
		if (((*token_list)->prev->prev->prev->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_DR_REDIR)
			&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
			&& ((*token_list)->prev->prev->toktype == TOK_FILE)
			&& ((*token_list)->prev->toktype == TOK_SPACE))
				return (1);
	}
	return (0);
}

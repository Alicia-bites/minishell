/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 09:49:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_combo_heredoc(t_list **token_list)
{
	if ((*token_list)->index >= 4)
	{
		if ((*token_list)->prev->prev->prev->prev->index != 0)
		{
			if ((*token_list)->prev->prev->prev->prev->toktype == TOK_DL_REDIR
				&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
				&& ((*token_list)->prev->prev->toktype == TOK_HERESEP)
				&& ((*token_list)->prev->toktype == TOK_SPACE))
					return (1);
		}
	}
	return (0);
}

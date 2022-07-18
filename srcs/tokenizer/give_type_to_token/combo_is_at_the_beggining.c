/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo_is_at_the_beggining.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:06:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 14:06:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	combo_is_at_the_beggining(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->index == 0)
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
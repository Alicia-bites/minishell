/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo_is_after_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:06:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 10:32:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	combo_is_after_pipe(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->toktype == TOK_PIPE)
	{
		if (((*token_list)->prev->prev->toktype == TOK_L_REDIR
				|| (*token_list)->prev->prev->toktype == TOK_R_REDIR
				|| (*token_list)->prev->prev->toktype == TOK_DR_REDIR)
			&& (*token_list)->prev->toktype == TOK_FILE)
			return (1);
	}
	return (0);
}

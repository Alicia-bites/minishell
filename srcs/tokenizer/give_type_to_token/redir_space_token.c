/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_space_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:43 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 09:50:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if token is preceded by a space and then <, > or >>
int	redir_space_token(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if (((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_L_REDIR)
			|| ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_R_REDIR)
			|| ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_DR_REDIR))
				return (1);		
	}
	return (0);
}

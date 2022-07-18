/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_space_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:37:00 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 09:37:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if token is followed by a space and then <, > or >>
int	token_space_redir(t_list **token_list)
{
	if ((*token_list)->next && (*token_list)->next->next)
	{
		if (((*token_list)->next->toktype == TOK_SPACE
			&& (*token_list)->next->next->toktype == TOK_L_REDIR)
			|| ((*token_list)->next->toktype == TOK_SPACE
			&& (*token_list)->next->next->toktype == TOK_R_REDIR)
			|| ((*token_list)->next->toktype == TOK_SPACE
			&& (*token_list)->next->next->toktype == TOK_DR_REDIR))
				return (1);		
	}
	return (0);
}

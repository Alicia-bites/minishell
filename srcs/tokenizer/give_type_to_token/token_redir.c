/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:54 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 09:50:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//check if token is followed by <, > or >>
int	token_redir(t_list **token_list)
{
	if ((*token_list)->next)
	{
		if (((*token_list)->next->toktype == TOK_L_REDIR
			|| (*token_list)->next->toktype == TOK_R_REDIR
			|| (*token_list)->next->toktype == TOK_DR_REDIR))
			return (1);	
	}
	return (0);
}
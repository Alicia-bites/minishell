/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 09:50:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//check if token is preceded by <, > or >>
int	redir_token(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if (((*token_list)->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->toktype == TOK_DR_REDIR))
			return (1);	
	}
	return (0);
}

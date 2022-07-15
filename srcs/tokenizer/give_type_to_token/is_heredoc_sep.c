/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:39 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 10:24:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is a heredoc separator a token that is placed after <<
// or after << and then a space
int	is_heredoc_sep(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_DL_REDIR)
			return (1);
	}
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_DL_REDIR)
				return (1);
	
	}
	return (0);
}
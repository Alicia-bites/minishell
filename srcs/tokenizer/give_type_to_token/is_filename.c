/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:37 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 14:43:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_after_SEP(t_list **token_list)
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

// Is filename a token that is placed after a <, > or >>
// or after a <, > or >> and then a space
int	is_filename(t_list **token_list)
{
	if (redir_token(token_list))
		return (1);		
	if (redir_space_token(token_list))
		return (1);
	return (0);
}

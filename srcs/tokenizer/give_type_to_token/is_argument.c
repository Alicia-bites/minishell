/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 14:37:56 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is argument a token that is a $, or preceded by a space and then
// a built-in or a command
int	is_argument(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->prev->toktype == TOK_BUILTIN
			&& (ft_strcmp((*token_list)->token, "$"))
			|| ((*token_list)->prev->prev->toktype == TOK_CMD))
				return (1);
	}
	if (is_combo_redir(token_list))
		return (1);
	if (is_combo_heredoc(token_list))
		return (1);
	if ((*token_list)->toktype == TOK_ARG)
	{
		while (*token_list && !is_operator((*token_list)->token))
		{
			if (!only_space_in_str((*token_list)->token))
				(*token_list)->toktype = TOK_SPACE;
			else
				(*token_list)->toktype = TOK_ARG;
			*token_list = (*token_list)->next;
		}
		if ((*token_list))
			*token_list = (*token_list)->prev;
		return (1);
	}
	return (0);	
}

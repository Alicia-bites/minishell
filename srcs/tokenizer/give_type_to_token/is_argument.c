/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 18:23:09 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	following_file_or_sep(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_FILE
			|| (*token_list)->prev->toktype == TOK_HERESEP)
			return (1);
	}
	return (0);
}

// Is argument a token that is a $, or preceded by a space and then
// a built-in or a command
int	is_argument(t_list **token_list)
{
	extern t_global	global;
	
	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_BUILTIN
			&& (ft_strcmp((*token_list)->token, "$"))
			|| ((*token_list)->prev->toktype == TOK_CMD))
				(*token_list)->toktype = TOK_ARG;
	}
	if (is_combo_redir(token_list))
		(*token_list)->toktype = TOK_ARG;
	else if (is_combo_heredoc(token_list))
		(*token_list)->toktype = TOK_ARG;
	if (following_file_or_sep(token_list) && global.seen_tok_cmd)
		(*token_list)->toktype = TOK_ARG;
	else if (following_file_or_sep(token_list) && !global.seen_tok_cmd)
	{
		global.seen_tok_cmd = 1;
		(*token_list)->toktype = TOK_CMD;
	}
	if ((*token_list)->toktype == TOK_ARG)
	{
		while (*token_list && !is_operator((*token_list)->token))
		{
			(*token_list)->toktype = TOK_ARG;
			*token_list = (*token_list)->next;
		}
		if ((*token_list))
			*token_list = (*token_list)->prev;
		return (1);
	}
	return (0);
}

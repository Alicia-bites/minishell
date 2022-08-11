/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:43:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	following_file_or_sep(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_FILE
			|| (*token_list)->prev->toktype == TOK_HERESEP)
			return (1);
	}
	return (0);
}

static int	loop_on_arg(t_list **token_list)
{
	while ((*token_list)->next
		&& not_operator((*token_list)->next))
	{
		(*token_list)->next->toktype = TOK_ARG;
		*token_list = (*token_list)->next;
	}
	return (1);
}

// Is argument a token that is a $, or preceded by a space and then
// a built-in or a command
int	is_argument(t_list **token_list)
{
	extern t_global	g_msl;

	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_BUILTIN
			|| ((*token_list)->prev->toktype == TOK_CMD))
				(*token_list)->toktype = TOK_ARG;
	}
	if (is_combo_redir(token_list))
		(*token_list)->toktype = TOK_ARG;
	else if (is_combo_heredoc(token_list))
		(*token_list)->toktype = TOK_ARG;
	if (following_file_or_sep(token_list) && g_msl.seen_tok_cmd)
		(*token_list)->toktype = TOK_ARG;
	else if (following_file_or_sep(token_list) && !g_msl.seen_tok_cmd)
	{
		g_msl.seen_tok_cmd = 1;
		(*token_list)->toktype = TOK_CMD;
	}
	if ((*token_list)->toktype == TOK_ARG)
		return (loop_on_arg(token_list));
	return (0);
}

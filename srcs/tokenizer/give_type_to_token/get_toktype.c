/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_toktype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 11:25:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_toktype_second(t_list **token_list, int *seen_cmd)
{
	if (is_heredoc_sep(token_list))
		(*token_list)->toktype = TOK_HERESEP;
	else if (is_argument(token_list, seen_cmd))
		NULL;
	else if (is_cmd(token_list, seen_cmd))
	{
		*seen_cmd = 1;
		(*token_list)->toktype = TOK_CMD;
	}
}

void	get_toktype(t_list **token_list)
{
	t_list			*it;
	int				seen_cmd;

	seen_cmd = 0;
	it = *token_list;
	while (*token_list)
	{
		if (is_built_in(token_list, &seen_cmd))
			NULL;
		else if (is_operator((*token_list)->token, &seen_cmd)
			&& (*token_list)->toktype != TOK_NOT_OP
			&& (*token_list)->toktype == TOK_UNKNOWN)
			(*token_list)->toktype
				= is_operator((*token_list)->token, &seen_cmd);
		else if (!only_space_in_str((*token_list)->token)
			&& (*token_list)->toktype != TOK_CMD)
			(*token_list)->toktype = TOK_SPACE;
		else if (is_filename(token_list))
			(*token_list)->toktype = TOK_FILE;
		else
			get_toktype_second(token_list, &seen_cmd);
		if (*token_list)
			*token_list = (*token_list)->next;
	}
	*token_list = it;
}

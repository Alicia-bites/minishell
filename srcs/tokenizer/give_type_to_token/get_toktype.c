/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_toktype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 18:20:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_toktype(t_list **token_list)
{
	t_list	*it;
	extern t_global	global;
	static int	tmp;
	
	global.seen_tok_cmd = 0;
	it = *token_list;
	tmp = global.ignore_op;
	while (*token_list)
	{
		if (is_built_in(token_list))
			NULL;
		else if (is_operator((*token_list)->token))
			(*token_list)->toktype = is_operator((*token_list)->token);
		else if (!only_space_in_str((*token_list)->token))
			(*token_list)->toktype = TOK_SPACE;
		else if (!only_space_in_str((*token_list)->token))
			(*token_list)->toktype = TOK_CMD;
		else if (is_filename(token_list))
			(*token_list)->toktype = TOK_FILE;
		else if (is_heredoc_sep(token_list))
			(*token_list)->toktype = TOK_HERESEP;
		else if (is_argument(token_list))
			NULL;
		else if (is_cmd(token_list))
		{
			global.seen_tok_cmd = 1;
			(*token_list)->toktype = TOK_CMD;			
		}
		if (*token_list)
			*token_list = (*token_list)->next;
	}
	*token_list = it;
}

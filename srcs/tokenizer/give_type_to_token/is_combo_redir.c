/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/15 15:22:40 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_cmd_redir_file_token(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->prev->prev->prev->prev->toktype
			== TOK_PIPE)
	{
		if ((*token_list)->prev->prev->prev->prev->prev->prev->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->prev->prev->prev->prev->toktype == TOK_CMD
			&& (*token_list)->prev->prev->prev->prev->prev->toktype == TOK_SPACE
			&& ((*token_list)->prev->prev->prev->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_DR_REDIR)
			&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
			&& ((*token_list)->prev->prev->toktype == TOK_FILE)
			&& ((*token_list)->prev->toktype == TOK_SPACE))
				return (1);
	}
	return (0);
}

int	start_cmd_redir_file_token(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->prev->prev->index == 0)
	{
		printf("%d\n", (*token_list)->prev->prev->prev->prev->prev->prev->toktype);
		if (((*token_list)->prev->prev->prev->prev->prev->prev->toktype == TOK_CMD)
			&& (*token_list)->prev->prev->prev->prev->prev->toktype == TOK_SPACE	
			&& ((*token_list)->prev->prev->prev->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_DR_REDIR)
			&& (*token_list)->prev->prev->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_FILE
			&& (*token_list)->prev->toktype == TOK_SPACE)
				return (1);
	}
	return (0);
}

// Check if we have a valid redirection combination in 2 situations :
// 1. if we have this combition after a pipe
// 2. if we have it at the beggining of the line.
// This if allows to token not be considered as argument if line starts with
// redir operator.
int	is_combo_redir(t_list **token_list)
{
	if (following_pipe(token_list))
		return (0);
	if ((*token_list)->index >= 8)
	{
		if (pipe_cmd_redir_file_token(token_list))
			return (1);
	}
	else if ((*token_list)->index >= 6)
		if (start_cmd_redir_file_token(token_list))
			return (1);
	return (0);
}

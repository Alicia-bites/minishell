/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 10:45:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_combo_is_after_pipe(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->prev->prev->toktype
			== TOK_PIPE)
	{
		if ((*token_list)->prev->prev->prev->prev->toktype == TOK_DL_REDIR
			&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
			&& ((*token_list)->prev->prev->toktype == TOK_HERESEP)
			&& ((*token_list)->prev->toktype == TOK_SPACE))
				return (1);
	}
	return (0);
}

int	heredoc_combo_is_at_the_beggining(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->index == 0)
	{
		if ((*token_list)->prev->prev->prev->prev->toktype == TOK_DL_REDIR
			&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
			&& ((*token_list)->prev->prev->toktype == TOK_HERESEP)
			&& ((*token_list)->prev->toktype == TOK_SPACE))
				return (1);
	}
	return (0);
}

int	pipe_cmd_dlredir_sep_token(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->prev->prev->prev->prev->toktype
			== TOK_PIPE)
	{
		if ((*token_list)->prev->prev->prev->prev->prev->toktype == TOK_CMD
			&& (*token_list)->prev->prev->prev->prev->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->prev->prev->toktype == TOK_DL_REDIR
			&& (*token_list)->prev->prev->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_HERESEP
			&& (*token_list)->prev->toktype == TOK_SPACE)
				return (1);
	}
	return (0);
}

int	start_cmd_dlredir_sep_token(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->prev->prev->index == 0)
	{
		if ((*token_list)->prev->prev->prev->prev->prev->prev->toktype == TOK_CMD
			&& (*token_list)->prev->prev->prev->prev->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->prev->prev->toktype == TOK_DL_REDIR
			&& (*token_list)->prev->prev->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_HERESEP
			&& (*token_list)->prev->toktype == TOK_SPACE)
				return (1);
	}
	return (0);
}

int	is_combo_heredoc(t_list **token_list)
{
	if (following_pipe(token_list))
		return (0);
	if ((*token_list)->index >= 7)
	{
		if (pipe_cmd_dlredir_sep_token(token_list))
			return (1);			
	}
	else if ((*token_list)->index >= 6)
		if (start_cmd_dlredir_sep_token(token_list))
			return (1);
	return (0);
}
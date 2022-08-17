/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:29:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 16:40:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is command a token that is not placed before or after a redirection.
int	is_cmd(t_list **token_list, int *seen_cmd)
{
	if (((*token_list)->index == 0 || following_pipe(token_list))
		&& not_operator((*token_list), seen_cmd))
	{
		*seen_cmd = 1;
		return (1);
	}
	if (is_combo_redir_when_redir_index_zero(token_list))
		return (1);
	if (cmd_redir(token_list, seen_cmd))
		return (1);
	if (cmd_heredoc(token_list, seen_cmd))
		return (1);
	if (combo_heredoc_when_heredoc_index_zero(token_list))
		return (1);
	return (0);
}

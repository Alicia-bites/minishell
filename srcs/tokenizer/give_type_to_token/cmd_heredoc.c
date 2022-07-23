/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:44:32 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 10:30:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_heredoc(t_list **token_list)
{
	if ((*token_list)->index == 0 || following_pipe(token_list))
	{
		if (is_operator((*token_list)->next->token) == TOK_DR_REDIR)
			return (1);
	}
	return (0);
}

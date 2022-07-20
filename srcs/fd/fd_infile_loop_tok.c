/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_infile_loop_tok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:30:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 10:31:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*fd_infile_loop_tok(t_list *tok, t_cmd *cmd)
{
	t_list	*obj;

	obj = tok;
	while (obj && !(obj->toktype == TOK_PIPE))
	{
		if (obj->toktype == TOK_L_REDIR)
		{
			obj = obj->next;
			if (cmd->fd_r == FD_NOT_INIT || cmd->fd_r >= 0)
				fd_infile_open(cmd, obj->token);
		}
		obj = obj->next;
	}
	return (obj);
}

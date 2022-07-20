/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_loop_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:30:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 16:40:15 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*fd_loop_tok(t_list *tok, t_cmd *cmd, enum e_toktype toktype, int mode)
{
	t_list	*obj;

	obj = tok;
	while (obj && !(obj->toktype == TOK_PIPE))
	{
		if (obj->toktype == toktype)
		{
			obj = obj->next;
			if (toktype == TOK_L_REDIR
				&& (cmd->fd_r == FD_NOT_INIT || cmd->fd_r >= 0))
				fd_infile_open(cmd, obj->token, mode);
			else if ((toktype == TOK_R_REDIR
					|| toktype == TOK_DR_REDIR)
				&& (cmd->fd_w == FD_NOT_INIT || cmd->fd_w >= 0))
				fd_outfile_open(cmd, obj->token, mode);
		}
		obj = obj->next;
	}
	return (obj);
}

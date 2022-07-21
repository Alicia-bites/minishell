/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_loop_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:30:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 13:46:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*fd_loop_tok(t_list *tok, t_cmd *cmd, int mode)
{
	t_list			*obj;
	enum e_toktype	toktype;
	int				res;

	obj = tok;
	res = 0;
	while (obj && !(obj->toktype == TOK_PIPE))
	{
		if (res == 0 && (obj->toktype == TOK_L_REDIR
				|| obj->toktype == TOK_R_REDIR
				|| obj->toktype == TOK_DR_REDIR
				|| obj->toktype == TOK_DL_REDIR))
		{
			toktype = obj->toktype;
			obj = obj->next;
			res = fd_loop_tok_type(obj, cmd, toktype, mode);
		}
		obj = obj->next;
	}
	if (res && cmd->fd_r >= 0)
		close(cmd->fd_r);
	if (res && cmd->fd_w >= 0)
		close(cmd->fd_w);
	return (obj);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_loop_tok_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:03:23 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 13:25:45 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_loop_tok_type(t_list *obj, t_cmd *cmd,
		enum e_toktype toktype, int mode)
{
	(void)mode;
	if (toktype == TOK_L_REDIR
		&& (cmd->fd_r == FD_NOT_INIT || cmd->fd_r >= 0))
		return (fd_infile_open(cmd, obj->token, O_RDONLY));
	else if (toktype == TOK_DL_REDIR
		&& (cmd->fd_r == FD_NOT_INIT || cmd->fd_r >= 0))
		return (printf("HERE DOC TO BE DONE\n"));
	else if (toktype == TOK_R_REDIR
		&& (cmd->fd_w == FD_NOT_INIT || cmd->fd_w >= 0))
		return (fd_outfile_open(cmd, obj->token, O_WRONLY));
	else if (toktype == TOK_DR_REDIR
		&& (cmd->fd_w == FD_NOT_INIT || cmd->fd_w >= 0))
		return (fd_outfile_open(cmd, obj->token, O_APPEND));
	else
		return (0);
}

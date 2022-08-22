/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_pfd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 09:13:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_pfd(int pfd)
{
	close(pfd);
	pfd = FD_NOT_INIT;
}

void	pipe_close_pfd(void *content)
{
	t_cmd	*cmd;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	if (!cmd)
		return ;
	if (cmd->fd_r > 2)
		close_pfd(cmd->fd_r);
	if (cmd->fd_w > 2)
		close_pfd(cmd->fd_w);
	if (cmd->pfd_r >= 2)
		close_pfd(cmd->pfd_r);
	if (cmd->pfd_w >= 2)
		close_pfd(cmd->pfd_w);
}

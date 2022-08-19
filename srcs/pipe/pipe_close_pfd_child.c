/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_pfd_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 09:21:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_close_pfd_child(void *content)
{
	t_cmd	*cmd;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	if (!cmd)
		return ;
	if (cmd->fd_r > 2)
	{
		close(cmd->fd_r);
		cmd->fd_r = FD_NOT_INIT;
	}
	if (cmd->fd_w > 2)
	{
		close(cmd->fd_w);
		cmd->fd_w = FD_NOT_INIT;
	}
	if (cmd->pfd_r > 2)
	{
		close(cmd->pfd_r);
		cmd->pfd_r = FD_NOT_INIT;
	}
	if (cmd->pfd_w > 2)
	{
		close(cmd->pfd_w);
		cmd->pfd_w = FD_NOT_INIT;
	}
}

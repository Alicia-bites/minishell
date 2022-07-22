/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_dup_fd_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:09:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 13:41:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd_dup_fd_out(t_ulist **cmd_lst, t_cmd *cmd)
{
	if (cmd->fd_w == FD_NOT_INIT && cmd->pfd_w == FD_NOT_INIT)
	{
		// SINGLE COMMAND (CMD_LST SIZE = 1)
		// NO INFILE
		// LAST COMMAND
	}
	else if (cmd->fd_w >= 0 && cmd->pfd_w == FD_NOT_INIT)
	{
		// INFILE
		// LAST COMMAND
		dup2(cmd->fd_w, STDOUT_FILENO);
	}
	else if (cmd->fd_w == FD_NOT_INIT && cmd->pfd_w >= 0)
	{
		// NO INFILE
		// COMMAND PIPED (FIRST ONE OR MIDDLE)
		dup2(cmd->pfd_w, STDOUT_FILENO);
	}
	else if (cmd->fd_w >= 0 && cmd->pfd_w >= 0)
	{
		// INFILE
		// COMMAND PIPED (MIDDLE OR LAST ONE)
		dup2(cmd->fd_w, STDOUT_FILENO);
	}
	else
	{
		// ERROR
		// POSSIBLE INFILE = -1
		// EXIT FAILURE
		pipe_exit(cmd_lst, cmd);
	}
}

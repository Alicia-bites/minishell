/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_dup_fd_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:09:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 13:41:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd_dup_fd_in(t_ulist **cmd_lst, t_cmd *cmd)
{
	if (cmd->fd_r == FD_NOT_INIT && cmd->pfd_r == FD_NOT_INIT)
	{
		// SINGLE COMMAND (CMD_LST SIZE = 1)
		// NO INFILE
		// FIRST COMMAND
		printf("**%s** 0\n", __FILE__);
	}
	else if (cmd->fd_r >= 0 && cmd->pfd_r == FD_NOT_INIT)
	{
		// INFILE
		// FIRST COMMAND
		printf("**%s** 1\n", __FILE__);
		dup2(cmd->fd_r, STDIN_FILENO);
	}
	else if (cmd->fd_r == FD_NOT_INIT && cmd->pfd_r >= 0)
	{
		// NO INFILE
		// COMMAND PIPED (MIDDLE OR LAST ONE)
		printf("**%s** 2\n", __FILE__);
		dup2(cmd->pfd_r, STDIN_FILENO);
	}
	else if (cmd->fd_r >= 0 && cmd->pfd_r >= 0)
	{
		// INFILE
		// COMMAND PIPED (MIDDLE OR LAST ONE)
		printf("**%s** 3\n", __FILE__);
		dup2(cmd->fd_r, STDIN_FILENO);
	}
	else
	{
		// ERROR
		// POSSIBLE INFILE = -1
		// EXIT FAILURE
		printf("**%s** 4\n", __FILE__);
		pipe_exit(cmd_lst, cmd);
	}
}

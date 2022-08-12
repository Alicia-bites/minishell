/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_dup_fd_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:09:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 08:58:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @CASE 1:
 * SINGLE COMMAND (CMD_LST SIZE = 1)
 * NO INFILE
 * FIRST COMMAND
 *
 * @CASE 2:
 * INFILE
 * FIRST COMMAND
 *
 * @CASE 3:
 * NO INFILE
 * COMMAND PIPED (MIDDLE OR LAST ONE)
 *
 * @CASE 4:
 * INFILE
 * COMMAND PIPED (MIDDLE OR LAST ONE)
 *
 * @CASE 5:
 * ERROR
 * POSSIBLE INFILE = -1
 * EXIT FAILURE
 */
void	pipe_cmd_dup_fd_in(t_ulist **cmd_lst, t_cmd *cmd)
{
	errno = 0;
	if (cmd->fd_r == FD_NOT_INIT && cmd->pfd_r == FD_NOT_INIT)
		dup2(STDIN_FILENO, STDIN_FILENO);
	else if (cmd->fd_r >= 0 && cmd->pfd_r == FD_NOT_INIT)
		dup2(cmd->fd_r, STDIN_FILENO);
	else if (cmd->fd_r == FD_NOT_INIT && cmd->pfd_r >= 0)
		dup2(cmd->pfd_r, STDIN_FILENO);
	else if (cmd->fd_r >= 0 && cmd->pfd_r >= 0)
		dup2(cmd->fd_r, STDIN_FILENO);
	else if (cmd->fd_r < 0 && cmd->pfd_r < 0)
		pipe_exit(cmd_lst, cmd, EXIT_FAILURE);
	if (errno)
		pipe_exit(cmd_lst, cmd, errno);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_dup_fd_out.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:09:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 14:20:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @CASE 1:
 * SINGLE COMMAND (CMD_LST SIZE = 1)
 * NO INFILE
 * LAST COMMAND
 *
 * @CASE 2:
 * INFILE
 * LAST COMMAND
 *
 * @CASE 3:
 * NO INFILE
 * COMMAND PIPED (FIRST ONE OR MIDDLE)
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
int	do_builtin_dup_fd_out(t_ulist **cmd_lst, t_cmd *cmd)
{
	errno = 0;
	if (cmd->fd_w == FD_NOT_INIT && cmd->pfd_w == FD_NOT_INIT)
		dup2(STDOUT_FILENO, STDOUT_FILENO);
	else if (cmd->fd_w >= 0 && cmd->pfd_w == FD_NOT_INIT)
		dup2(cmd->fd_w, STDOUT_FILENO);
	else if (cmd->fd_w == FD_NOT_INIT && cmd->pfd_w >= 0)
		dup2(cmd->pfd_w, STDOUT_FILENO);
	else if (cmd->fd_w >= 0 && cmd->pfd_w >= 0)
		dup2(cmd->fd_w, STDOUT_FILENO);
	else if (cmd->fd_w < 0 && cmd->pfd_w < 0)
		errno = EXIT_FAILURE;
	if (errno)
		return (do_builtin_exit(errno));
	else
		return (0);
}

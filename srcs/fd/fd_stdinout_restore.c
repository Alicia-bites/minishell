/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_stdinout_restore.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:39:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_stdinout_restore(t_cmd *cmd, int fd_stdin, int fd_stdout)
{
	int	err_no;

	errno = 0;
	err_no = 0;
	if (cmd->fd_r > 2)
	{
		dup2(fd_stdin, STDIN_FILENO);
		cmd->fd_r = FD_NOT_INIT;
	}
	if (cmd->fd_w > 2)
	{
		dup2(fd_stdout, STDOUT_FILENO);
		cmd->fd_w = FD_NOT_INIT;
	}
	if (errno)
	{
		err_no = errno;
		ft_panic(-1, __func__, ERR_PFD);
	}
	fd_stdinout_backup_close(fd_stdin, fd_stdout);
	if (err_no)
		return (EXIT_FAILURE);
	else
		return (0);
}

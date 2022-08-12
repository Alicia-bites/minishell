/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_stdinout_restore.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:39:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 17:57:23 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_stdinout_restore(t_cmd *cmd, int fd_stdin, int fd_stdout)
{
	if (cmd->fd_r > 2)
		dup2(fd_stdin, STDIN_FILENO);
	if (cmd->fd_w > 2)
		dup2(fd_stdout, STDOUT_FILENO);
	if (fd_stdin > 2)
		close(fd_stdin);
	if (fd_stdout > 2)
		close(fd_stdout);
	if (errno)
		return (EXIT_FAILURE);
	else
		return (0);
}

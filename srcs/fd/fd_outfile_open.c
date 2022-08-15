/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_outfile_open.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:01:57 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 12:06:46 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_outfile_open(t_cmd *cmd, char *fd, int mode)
{
	if (cmd->fd_w > 2)
	{
		close(cmd->fd_w);
		cmd->fd_w = -1;
	}
	cmd->fd_w = fd_open(fd, mode);
	if (cmd->fd_w < 0)
	{
		if (access(fd, F_OK) == 0)
		{
			cmd->fd_w = fd_open(fd, mode);
			if (cmd->fd_w < 0)
				return (ft_shell_msg(errno, fd));
		}
		else if (access(fd, O_DIRECTORY) == 0)
			return (ft_shell_msg(EISDIR, fd));
		else
			return (fd_access(fd, 2));
	}
	return (0);
}

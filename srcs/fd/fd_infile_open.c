/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_infile_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:06:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 10:15:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_infile_open(t_cmd *cmd, char *fd)
{
	if (cmd->fd_r >= 0)
	{
		close(cmd->fd_r);
		cmd->fd_r = -1;
	}
	cmd->fd_r = open(fd, O_RDONLY);
	if (cmd->fd_r < 0)
		return (fd_access(fd, ACCESS_R));
	else
		return (0);
}

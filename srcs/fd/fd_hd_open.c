/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_hd_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:06:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 20:27:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_hd_open(t_cmd *cmd)
{
	if (cmd->fd_r > 2)
	{
		if (cmd->fd_r == cmd->hd_r)
		{
			close(cmd->hd_r);
			unlink(cmd->hd_name);
			cmd->hd_r = FD_NOT_INIT;
		}
		else
			close(cmd->fd_r);
		cmd->fd_r = -1;
	}
	cmd->fd_r = fd_open(cmd->hd_name, O_RDONLY);
	if (cmd->fd_r < 0)
		return (fd_access(cmd->hd_name, ACCESS_R));
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_link_cmd_in.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:11:58 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 11:19:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_init_tokfile_link_cmd_in(t_cmd *cmd, int fd)
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
	}
	cmd->fd_r = fd;
}

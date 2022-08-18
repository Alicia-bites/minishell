/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_link_cmd_secure.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:28:25 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 12:48:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_init_tokfile_link_cmd_secure(t_cmd *cmd, int fd)
{
	if (cmd->fd_r == -1 || cmd->fd_w == -1)
	{
		fd_close(cmd);
		cmd->fd_r = -1;
		cmd->fd_w = -1;
		return (1);
	}
	else if (cmd->fd_r != -1 && cmd->fd_w != -1 && fd == -1)
	{
		fd_close(cmd);
		cmd->fd_r = -1;
		cmd->fd_w = -1;
		return (0);
	}
	else
		return (0);
}

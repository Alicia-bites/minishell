/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_hd_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:06:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 13:48:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_hd_open(t_cmd *cmd)
{
	if (cmd->fd_r > 2)
	{
		close(cmd->fd_r);
		cmd->fd_r = -1;
	}
	cmd->fd_r = fd_open(cmd->hd_name, O_RDONLY);
	if (cmd->fd_r < 0)
		return (fd_access(cmd->hd_name, ACCESS_R));
	else
	{
		cmd->hd_r = cmd->fd_r;
		return (0);
	}
}

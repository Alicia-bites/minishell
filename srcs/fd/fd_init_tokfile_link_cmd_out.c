/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_link_cmd_out.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:11:58 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 11:19:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_init_tokfile_link_cmd_out(t_cmd *cmd, int fd)
{
	if (cmd->fd_w > 2)
		close(cmd->fd_w);
	cmd->fd_w = fd;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_pfd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 13:27:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_close_pfd(void *content)
{
	t_cmd	*cmd;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	if (!cmd)
		return ;
	if (cmd->fd_r >= 0)
		close(cmd->fd_r);
	if (cmd->fd_w >= 0)
		close(cmd->fd_w);
	if (cmd->pfd_r >= 0)
		close(cmd->pfd_r);
	if (cmd->pfd_w >= 0)
		close(cmd->pfd_w);
}

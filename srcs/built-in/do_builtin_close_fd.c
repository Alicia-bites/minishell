/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_close_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 14:28:57 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_builtin_close_fd(void *content)
{
	t_cmd	*cmd;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	if (!cmd)
		return ;
	if (cmd->fd_r > 2)
		close(cmd->fd_r);
	if (cmd->fd_w > 2)
		close(cmd->fd_w);
	if (cmd->pfd_r > 2)
		close(cmd->pfd_r);
	if (cmd->pfd_w > 2)
		close(cmd->pfd_w);
}

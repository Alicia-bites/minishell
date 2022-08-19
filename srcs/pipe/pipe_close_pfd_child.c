/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_pfd_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 11:21:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_close(int *fd)
{
	close(*fd);
	*fd = FD_NOT_INIT;
}

void	pipe_close_pfd_child(void *content)
{
	t_cmd	*cmd;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	if (!cmd)
		return ;
	if (cmd->fd_r > 2)
		ft_close(&cmd->fd_r);
	if (cmd->fd_w > 2)
		ft_close(&cmd->fd_w);
	if (cmd->pfd_r > 2)
		ft_close(&cmd->pfd_r);
	if (cmd->pfd_w > 2)
		ft_close(&cmd->pfd_w);
}

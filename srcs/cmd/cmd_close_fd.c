/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_close_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:39:37 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/11 17:58:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_close_fd(void *content)
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
}

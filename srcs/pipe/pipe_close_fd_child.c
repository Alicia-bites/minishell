/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_fd_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:44:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 16:45:10 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_close_fd_child(t_cmd *cmd)
{
	if (cmd->fd_r > 2)
		close(cmd->fd_r);
	if (cmd->fd_w > 2)
		close(cmd->fd_w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_loop_tok_secure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:23:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 18:23:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_loop_tok_secure(t_cmd *cmd, int res_loop)
{
	if (res_loop)
	{
		fd_close(cmd);
		cmd->fd_r = -1;
		cmd->fd_w = -1;
	}
	else
	{
		if (cmd->fd_r == FD_NOT_INIT)
			cmd->fd_r = STDIN_FILENO;
		if (cmd->fd_w == FD_NOT_INIT)
			cmd->fd_w = STDOUT_FILENO;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_default.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:45:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 14:50:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_default(t_ulist **cmd_lst)
{
	t_ulist	*obj;
	t_cmd	*cmd;

	obj = *cmd_lst;
	cmd = NULL;
	while (obj)
	{
		cmd = (t_cmd *)obj->content;
		if (cmd->fd_r == FD_NOT_INIT)
			cmd->fd_r = STDIN_FILENO;
		if (cmd->fd_w == FD_NOT_INIT)
			cmd->fd_w = STDOUT_FILENO;
		obj = obj->next;
	}
}

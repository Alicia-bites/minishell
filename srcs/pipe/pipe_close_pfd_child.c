/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_pfd_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 16:52:27 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_close_pfd_child(t_ulist **cmd_lst, t_cmd *pipe_active_cmd)
{
	t_ulist	*obj;
	t_cmd	*cmd;

	obj = *cmd_lst;
	cmd = NULL;
	while (obj)
	{
		cmd = (t_cmd *)obj->content;
		if (pipe_active_cmd != cmd)
		{
			if (cmd->pfd_r > 2)
				close(cmd->pfd_r);
			if (cmd->pfd_w > 2)
				close(cmd->pfd_w);
		}
		else
		{
			if (cmd->pfd_w > 2)
				close(cmd->pfd_w);
		}
		pipe_close_fd_child(cmd);
		obj = obj->next;
	}
}

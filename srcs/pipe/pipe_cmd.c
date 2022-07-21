/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:39:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 19:44:12 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd(t_ulist **cmd_lst, t_ulist *obj)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)obj->content;
	if (cmd->fd_r >= 0)
		dup2(cmd->fd_r, STDIN_FILENO);
	else
	{
		ft_lst_free(cmd_lst, cmd_free);
		exit(EXIT_FAILURE);
	}
	if (cmd->fd_w < 0)
	{
		ft_lst_free(cmd_lst, &cmd_free);
		exit(EXIT_FAILURE);
	}
	dup2(cmd->fd_w, STDOUT_FILENO);
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
	if (cmd->access == -1)
		ft_panic(-1, __FILE__, ERR_CMD_FOUND);
	else
		ft_shell_msg(errno, cmd->fullcmd[0]);
	ft_lst_free(cmd_lst, &cmd_free);
	exit(EXIT_FAILURE);
}

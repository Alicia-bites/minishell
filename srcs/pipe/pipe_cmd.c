/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:39:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/02 17:18:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd(t_ulist **cmd_lst, t_ulist *obj)
{
	t_cmd	*cmd;
	int		res;
	char	**envp;

	cmd = (t_cmd *)obj->content;
	res = 0;
	envp = env_char_set(cmd->env_lst);
	pipe_cmd_dup_fd_in(cmd_lst, cmd);
	pipe_cmd_dup_fd_out(cmd_lst, cmd);
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	if (cmd->toktype == TOK_BUILTIN)
		errno = do_builtin(cmd_lst, cmd);
	else
	{
		execve(cmd->fullcmd[0], cmd->fullcmd, envp);
		res = 1;
	}
	if (res || errno)
	{
		if (cmd->access == -1)
			errno = ft_panic_value(-1, __FILE__, ERR_CMD_FOUND, 127);
		else
			ft_shell_msg(errno, cmd->fullcmd[0]);
	}
	pipe_cmd_end(cmd_lst, cmd, errno, envp);
}

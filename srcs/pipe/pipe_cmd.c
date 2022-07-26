/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:39:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/26 15:07:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd(t_ulist **cmd_lst, t_ulist *obj)
{
	t_cmd	*cmd;
	int		res;
	char	**env_lst;

	cmd = (t_cmd *)obj->content;
	res = 0;
	env_lst = env_char_set(cmd->env_lst);
	pipe_cmd_dup_fd_in(cmd_lst, cmd);
	pipe_cmd_dup_fd_out(cmd_lst, cmd);
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	if (cmd->toktype == TOK_BUILTIN)
		res = do_builtin(cmd_lst, cmd);
	else
	{
		execve(cmd->fullcmd[0], cmd->fullcmd, env_lst);
		res = 1;
	}
	if (res)
	{
		if (cmd->access == -1)
			ft_panic(-1, __FILE__, ERR_CMD_FOUND);
		else
			ft_shell_msg(errno, cmd->fullcmd[0]);
	}
	if (env_lst)
		ft_free_ptrptr_str(env_lst);
	pipe_exit(cmd_lst, cmd);
}

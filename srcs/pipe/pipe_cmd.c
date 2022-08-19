/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:39:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 10:24:45 by abarrier         ###   ########.fr       */
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
	errno = 0;
	pipe_cmd_dup_fd_in(cmd_lst, cmd);
	pipe_cmd_dup_fd_out(cmd_lst, cmd);
	envp = env_char_set(cmd->env_lst);
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd_child);
	if (cmd->toktype == TOK_BUILTIN)
		errno = do_builtin(cmd_lst, cmd);
	else
	{
		if (!is_a_directory(cmd->tok_node->token, 0))
			execve(cmd->fullcmd[0], cmd->fullcmd, envp);
		res = 1;
	}
	handle_cmd_return_value(cmd, res);
	pipe_cmd_end(cmd_lst, cmd, errno, envp);
}

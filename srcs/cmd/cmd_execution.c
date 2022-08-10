/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/10 09:38:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_execution(t_ulist **cmd_lst, int n_cmd)
{
	t_cmd				*cmd;
	int					res;
	extern long long	g_msl_exit;

	cmd = NULL;
	res = 0;
	sig_program_unset_action();
	if (n_cmd == 1)
	{
		cmd = (t_cmd *)(*cmd_lst)->content;
		if (cmd->toktype == TOK_BUILTIN)
		{
			int	fd_stdin;
			int	fd_stdout;
			int	test;

			sig_pipe_set_action();
			fd_stdin = dup(STDIN_FILENO);
			fd_stdout = dup(STDOUT_FILENO);
			do_builtin_dup_fd_in(cmd_lst, cmd);
			do_builtin_dup_fd_out(cmd_lst, cmd);
			ft_lst_func_lst(cmd_lst, &do_builtin_close_fd);
			res = do_builtin(cmd_lst, cmd);
			if (cmd->fd_r > 2)
				dup2(fd_stdin, STDIN_FILENO);
			if (cmd->fd_w > 2)
				dup2(fd_stdout, STDOUT_FILENO);
			close(fd_stdin);
			close(fd_stdout);
		}
		else
			res = pipe_run(cmd_lst, n_cmd);
	}
	else
		res = pipe_run(cmd_lst, n_cmd);
	sig_program_set_action();
	g_msl_exit = res;
	return (res);
}

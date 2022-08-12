/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 09:39:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_execution(t_ulist **cmd_lst, int n_cmd)
{
	t_cmd				*cmd;
	int					res;
	extern t_global	g_msl;

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
			int	fd_stdin_back;
			int	fd_stdout_back;
			int	test;

			sig_pipe_set_action();
			fd_stdin = dup(STDIN_FILENO);
			fd_stdout = dup(STDOUT_FILENO);
			if (fd_stdin < 0 || fd_stdout < 0)
			{
				if (fd_stdin)
					close(fd_stdin);
				if (fd_stdout)
					close(fd_stdout);
				sig_program_set_action();
				g_msl.exit = 1;
				return (ft_panic(-1, __FILE__, ERR_PFD));
			}
			if (do_builtin_dup_fd_in(cmd_lst, cmd))
			{
				if (fd_stdin)
					close(fd_stdin);
				if (fd_stdout)
					close(fd_stdout);
				sig_program_set_action();
				g_msl.exit = 1;
				return (ft_panic(-1, __FILE__, ERR_PFD));
			}
			if (do_builtin_dup_fd_out(cmd_lst, cmd))
			{
				if (cmd->fd_r > 2)
					dup2(fd_stdin, STDIN_FILENO);
				if (fd_stdin > 2)
					close(fd_stdin);
				sig_program_set_action();
				g_msl.exit = 1;
				return (ft_panic(-1, __FILE__, ERR_PFD));
			}
			ft_lst_func_lst(cmd_lst, &do_builtin_close_fd);
			res = do_builtin(cmd_lst, cmd);
			if (cmd->fd_r > 2)
				dup2(fd_stdin, STDIN_FILENO);
			if (cmd->fd_w > 2)
				dup2(fd_stdout, STDOUT_FILENO);
			if (fd_stdin > 2)
				close(fd_stdin);
			if (fd_stdout > 2)
				close(fd_stdout);
		}
		else
			res = pipe_run(cmd_lst, n_cmd);
	}
	else
		res = pipe_run(cmd_lst, n_cmd);
	sig_program_set_action();
	g_msl.exit = res;
	return (res);
}

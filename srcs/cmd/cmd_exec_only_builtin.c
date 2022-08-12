/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_only_builtin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:05:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 18:09:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_exec_only_builtin(t_ulist **cmd_lst, t_cmd *cmd)
{
	int	fd_stdin;
	int	fd_stdout;
	int	res;

	if (fd_stdinout_backup(&fd_stdin, &fd_stdout))
		return (EXIT_FAILURE);
	if (do_builtin_dup_fd_in(cmd_lst, cmd))
	{
		fd_stdinout_backup_close(fd_stdin, fd_stdout);
		return (EXIT_FAILURE);
	}
	if (do_builtin_dup_fd_out(cmd_lst, cmd))
	{
		if (cmd->fd_r > 2)
			dup2(fd_stdin, STDIN_FILENO);
		fd_stdinout_backup_close(fd_stdin, fd_stdout);
		return (EXIT_FAILURE);
	}
	ft_lst_func_lst(cmd_lst, &do_builtin_close_fd);
	res = do_builtin(cmd_lst, cmd);
	if (fd_stdinout_restore(cmd, fd_stdin, fd_stdout))
		return (EXIT_FAILURE);
	return (res);
}

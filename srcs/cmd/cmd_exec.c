/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 17:24:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_exec(t_ulist **cmd_lst, int n_cmd)
{
	t_cmd			*cmd;
	int				res;
	extern t_global	g_msl;

	cmd = NULL;
	res = 0;
	sig_program_unset_action();
	if (n_cmd == 1)
	{
		cmd = (t_cmd *)(*cmd_lst)->content;
		if (cmd->toktype == TOK_BUILTIN)
		{
			sig_pipe_set_action();
			res = cmd_exec_only_builtin(cmd_lst, cmd);
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

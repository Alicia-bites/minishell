/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/03 13:59:48 by abarrier         ###   ########.fr       */
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
			sig_pipe_set_action();
			res = do_builtin(cmd_lst, cmd);
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

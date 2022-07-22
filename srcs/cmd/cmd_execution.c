/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 16:54:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_execution(t_ulist **cmd_lst, int n_cmd)
{
	t_cmd	*cmd;
	int		res;

	cmd = NULL;
	res = 0;
	if (n_cmd == 1)
	{
		cmd = (t_cmd *)(*cmd_lst)->content;
		if (cmd->toktype == TOK_BUILTIN)
			res = do_builtin(cmd_lst, cmd);
		else
			res = pipe_run(cmd_lst, n_cmd);
	}
	else
		res = pipe_run(cmd_lst, n_cmd);
	return (res);
}

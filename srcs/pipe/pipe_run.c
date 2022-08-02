/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:17:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/02 17:11:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_run(t_ulist **cmd_lst, int n_cmd)
{
	t_ulist	*obj;
	pid_t	pid;
	int		i;
	int		res;

	obj = *cmd_lst;
	i = 0;
	res = 0;
	while (obj && i < n_cmd)
	{
		pid = fork();
		if (pid < 0)
		{
			res = ft_panic_value(-1, __FILE__, ERR_FORK, 1);
			break ;
		}
		if (pid == 0)
		{
			sig_pipe_set_action();
			pipe_cmd(cmd_lst, obj);
		}
		obj = obj->next;
		i++;
	}
	return (pipe_run_end(cmd_lst, i, pid, res));
}

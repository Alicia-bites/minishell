/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:17:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/29 12:02:44 by abarrier         ###   ########.fr       */
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
	// TODO
	// set signal handling to default one
	while (obj && i < n_cmd)
	{
		pid = fork();
		if (pid < 0)
		{
			res = ft_panic_value(-1, __FILE__, ERR_PIPE, 1);
			break ;
		}
		if (pid == 0)
		{
			// TODO
			// change signal handling
			pipe_cmd(cmd_lst, obj);
		}
		obj = obj->next;
		i++;
	}
	// TODO
	// re set the signal handling as at the begining of the program
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	if (res == 0)
		res = pipe_wait(i, pid);
	return (res);
}

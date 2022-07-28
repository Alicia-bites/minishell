/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:17:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/27 20:25:46 by abarrier         ###   ########.fr       */
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
			res = ft_panic_value(-1, __FILE__, ERR_PIPE,
					EXIT_FAILURE);
			break ;
		}
		if (pid == 0)
			pipe_cmd(cmd_lst, obj);
		obj = obj->next;
		i++;
	}
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	if (res == 0)
		res = pipe_wait(i, pid);
	return (res);
}

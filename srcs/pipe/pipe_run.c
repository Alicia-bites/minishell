/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:17:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 19:45:47 by abarrier         ###   ########.fr       */
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
			res += ft_panic(-1, __FILE__, ERR_PIPE);
			break ;
		}
		if (pid == 0)
			pipe_cmd(cmd_lst, obj);
		obj = obj->next;
		i++;
	}
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	res += pipe_wait(i, pid);
	return (res);
}

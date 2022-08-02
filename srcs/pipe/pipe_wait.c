/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:23:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/02 16:54:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @BRIEF:
 * loop through all child process to get their exit status and
 * return the exit status of the last command
 *
 * @PARAM:
 * int n_cmd: total of command
 * int pid: pid of the last command
 *
 * @RETURN:
 * >= 0: expected exit value (0, SIGQUIT, SIGINT or command exit value)
 */
int	pipe_wait(int n_cmd, int pid)
{
	int	status_last;
	int	status_child;
	int	i;
	int	res_last;
	int	res_child;

	status_last = 0;
	i = 0;
	res_last = 0;
	res_child = 0;
	waitpid(pid, &status_last, 0);
	n_cmd--;
	while (i < n_cmd)
	{
		status_child = 0;
		waitpid(-1, &status_child, 0);
		res_child += pipe_wait_check_child(status_child);
		i++;
	}
	res_last = pipe_wait_check_last(status_last);
	return (pipe_wait_return(status_last, res_last, res_child));
}

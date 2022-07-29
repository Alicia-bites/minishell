/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:23:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/29 12:05:31 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_wait(int n_cmd, int pid)
{
	int	status;
	int	status_child;
	int	i;
	int	res;

	status = 0;
	status_child = 0;
	i = 0;
	res = 0;
	waitpid(pid, &status, 0);
	n_cmd--;
	while (i < n_cmd)
	{
		status_child = 0;
		waitpid(-1, &status_child, 0);
		if (WIFSIGNALED(status_child) == 1)
			res++;
		i++;
	}
	// TODO
	// Add hierarchy of SIGNAL MACRO
	// Most of WAITPID SIGNAL handling
	// IFEXITED
	// IF....
	if (WIFSIGNALED(status) == 1)
		res++;
	if (res)
		return (130);
	else
		return (WEXITSTATUS(status));
}

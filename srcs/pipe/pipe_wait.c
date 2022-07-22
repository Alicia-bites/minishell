/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:23:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 11:14:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_wait(int n_cmd, int pid)
{
	int	status;
	int	i;

	status = 1;
	i = 0;
	waitpid(pid, &status, 0);
	n_cmd--;
	while (i < n_cmd)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	return (status);
}

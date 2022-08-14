/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait_check_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:56:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 16:44:57 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check if command child exited by a signal and return a value
 *
 * @PARAM:
 * int status: returned status of the command (0, SIGQUIT, SIGINT)
 *
 * @RETURN:
 * = 0: the command exited without signal
 * > 0: the command exited by a signal
 */
int	pipe_wait_check_child(int status)
{
	int	res;

	res = 0;
	if (WIFSIGNALED(status) == 1)
	{
		if (WTERMSIG(status) == SIGINT)
			res = 130;
		else if (WTERMSIG(status) == SIGQUIT)
			res = 0;
	}
	return (res);
}

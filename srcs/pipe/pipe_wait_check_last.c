/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait_check_last.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:41:29 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 11:01:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check if last command exited by a signal, print specific message and
 * return a value
 *
 * @PARAM:
 * int status: returned status of the command (0, SIGQUIT, SIGINT)
 *
 * @RETURN:
 * = 0: the command exited without signal
 * > 0: the command exited by a signal
 */
int	pipe_wait_check_last(int status)
{
	int	res;

	res = 0;
	if (WIFSIGNALED(status) == 1)
	{
		if (WTERMSIG(status) == SIGINT)
		{
			res = 130;
			printf("\n");
		}
		if (WTERMSIG(status) == SIGQUIT)
		{
			res = 131;
			printf("%s\n", ERR_COREDUMP);
		}
		if (WTERMSIG(status) == SIGSEGV)
		{
			res = 139;
			ft_putendl_fd(MSGERR_SIGCATCH, 2);
		}
	}
	return (res);
}

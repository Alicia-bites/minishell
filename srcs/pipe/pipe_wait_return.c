/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:15:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 16:44:45 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check how last command exited and print a carriage return in case of 
 * then return expected exit value
 *
 * @PARAM:
 * int status_last: returned status of the last command (from waitpid)
 * int res_last: returned value of the last command (0, SIGQUIT, SIGINT)
 * int res_child: sum of returned value of the command (0, SIGQUIT, SIGINT)
 *
 * @RETURN:
 * >= 0: expected exit value (0, SIGQUIT, SIGINT or command exit value)
 */
int	pipe_wait_return(int status_last, int res_last, int res_child)
{
	if (res_last == 0 && res_child > 0)
		printf("\n");
	if (res_last)
		return (res_last);
	else
		return (WEXITSTATUS(status_last));
}

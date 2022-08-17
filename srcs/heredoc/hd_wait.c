/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:14:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 16:08:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_wait(int pid)
{
	extern t_global	g_msl;
	int				status;

	status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) == 1)
	{
		if (WEXITSTATUS(status) == 1)
			g_msl.exit = 130;
		else
			g_msl.exit = 0;
		return (WEXITSTATUS(status));
	}
	return (0);
}
/* SAVE TEST
 *
 *	if (WIFEXITED(status) == 1)
 *	{
 *		g_msl.exit = 130;
 *		if (WEXITSTATUS(status) == 1)
 *			return (WEXITSTATUS(status));
 *	}
 *	if (WIFSIGNALED(status) == 1)
 *	{
 *		if (WTERMSIG(status) == SIGINT)
 *		{
 *			printf("hd SIGINT\n");
 *			return (WTERMSIG(status));
 *		}
 *		else if (WTERMSIG(status) == SIGQUIT)
 *			printf("hd SIGQUIT\n");
 *		else if (WTERMSIG(status) == SIGCONT)
 *			printf("hd SIGCONT\n");
 *		else
 *		{
 *			printf("hd signal something\n");
 *			printf("hs signal = %d\n", WTERMSIG(status));
 *		}
 *	}
 *	if (WIFSTOPPED(status) == 1)
 *		printf("hd stopped\n");
 *	if (WIFCONTINUED(status) == 1)
 *		printf("hd continued\n");
 */

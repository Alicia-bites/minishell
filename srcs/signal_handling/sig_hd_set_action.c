/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_hd_set_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:14:03 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 12:39:06 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @BRIEF:
 * set int signal behaviour to default one to be able to stop the process
 * and do not redisplay prompt bask
 *
 * @PARAM:
 * void
 *
 * @RETURN:
 * 0: ok
 * >= 0: error
 */
static void	sig_hd_int(int signum)
{
	char *filename;
	char *fullcmd[2];

	filename = HD_BIN_FALSE;
	fullcmd[0] = HD_BIN_FALSE;
	fullcmd[1] = NULL;
	execve(filename, fullcmd, NULL);
}

int	sig_hd_set_action(void)
{
	signal(SIGINT, &sig_hd_int);
	return (0);
}

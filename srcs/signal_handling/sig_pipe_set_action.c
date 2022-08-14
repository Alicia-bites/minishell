/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_pipe_set_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:14:03 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 16:43:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
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
int	sig_pipe_set_action(void)
{
	signal(SIGINT, SIG_DFL);
	return (0);
}

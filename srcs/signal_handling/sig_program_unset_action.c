/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_program_unset_action.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 16:44:23 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * ignoring int signal behaviour
 * and set quit signal behaviour to authorized it but not exit the program
 *
 * @PARAM:
 * void
 *
 * @RETURN:
 * 0: ok
 * >= 0: error
 */
int	sig_program_unset_action(void)
{
	signal(SIGQUIT, &sig_pipe_quit);
	signal(SIGINT, SIG_IGN);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_pipe_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:04:39 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 08:43:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * do nothing to not use quit default behaviour
 * and let displaying quit message at the end of waitpid function
 *
 * @PARAM:
 * int signum: received signal number
 *
 * @RETURN:
 * N/A
 */
void	sig_pipe_quit(int signum)
{
	(void)signum;
	return ;
}

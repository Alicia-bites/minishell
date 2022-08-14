/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_hd_sigint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 08:42:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_hd_sigint(int signum)
{
	char	*filename;
	char	*fullcmd[2];

	(void)signum;
	filename = HD_BIN_FALSE;
	fullcmd[0] = HD_BIN_FALSE;
	fullcmd[1] = NULL;
	execve(filename, fullcmd, NULL);
}

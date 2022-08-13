/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_hd_sigint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 12:18:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_hd_sigint(int signum)
{
	char	*filename;
	char	*fullcmd[2];

	filename = HD_BIN_FALSE;
	fullcmd[0] = HD_BIN_FALSE;
	fullcmd[1] = NULL;
	execve(filename, fullcmd, NULL);
}

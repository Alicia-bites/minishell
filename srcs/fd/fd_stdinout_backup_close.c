/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_stdinout_backup_close.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:02:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 18:05:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_stdinout_backup_close(int fd_stdin, int fd_stdout)
{
	if (fd_stdin > 2)
		close(fd_stdin);
	if (fd_stdout > 2)
		close(fd_stdout);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_stdinout_backup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:26:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 18:10:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_stdinout_backup(int *fd_stdin, int *fd_stdout)
{
	*fd_stdin = dup(STDIN_FILENO);
	*fd_stdout = dup(STDOUT_FILENO);
	if (*fd_stdin < 0 || *fd_stdout < 0)
	{
		fd_stdinout_backup_close(*fd_stdin, *fd_stdout);
		return (ft_panic_value(-1, __FILE__, ERR_PFD, EXIT_FAILURE));
	}
	return (0);
}

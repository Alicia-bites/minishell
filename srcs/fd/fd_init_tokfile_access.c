/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_access.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:57:03 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 12:48:39 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_init_tokfile_access(int fd, char *fd_name, int mode)
{
	if (mode == O_RDONLY && fd < 0)
		return (fd_access(fd_name, ACCESS_R));
	else if ((mode == O_WRONLY || mode == O_APPEND) && fd < 0)
	{
		if (access(fd_name, F_OK) == 0)
			return (ft_shell_msg(errno, fd_name));
		else if (access(fd_name, O_DIRECTORY) == 0)
			return (ft_shell_msg(EISDIR, fd_name));
		else
			return (fd_access(fd_name, ACCESS_W));
	}
	return (0);
}

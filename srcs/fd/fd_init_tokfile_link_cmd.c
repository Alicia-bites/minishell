/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_link_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:41:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 17:01:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_init_tokfile_link_cmd(t_cmd *cmd, int fd, int mode, char *fd_name)
{
	(void)fd_name;
	if (cmd)
	{
		if (mode == O_RDONLY)
			fd_init_tokfile_link_cmd_in(cmd, fd);
		else if (mode == O_WRONLY || mode == O_APPEND)
			fd_init_tokfile_link_cmd_out(cmd, fd);
	}
	else
	{
		close(fd);
		if (fd_name)
			unlink(fd_name);
		errno = 0;
	}
}

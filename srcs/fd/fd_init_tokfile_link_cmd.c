/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_link_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:41:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 17:03:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_init_tokfile_link_cmd(t_cmd *cmd, int fd, int mode, char *fd_name)
{
	if (cmd)
	{
		if (mode == O_RDONLY)
			fd_init_tokfile_link_cmd_in(cmd, fd);
		else if (mode == O_WRONLY || mode == O_APPEND)
			fd_init_tokfile_link_cmd_out(cmd, fd);
		if (fd_name)
			free(fd_name);
	}
	else
	{
		if (fd > 2)
			close(fd);
		if (fd_name)
		{	
			unlink(fd_name);
			free(fd_name);
		}
		errno = 0;
	}
}

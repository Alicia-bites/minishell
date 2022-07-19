/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:06:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/19 16:16:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_infile(t_ulist *obj, char *fd)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)obj->content;
	if (cmd->fd_r >= 0)
		cmd->fd_r = -1;
	cmd->fd_r = open(fd, O_RDONLY);
	if (cmd->fd_r < 0)
		return (fd_access(fd, ACCESS_R));
	else
		return (0);
}

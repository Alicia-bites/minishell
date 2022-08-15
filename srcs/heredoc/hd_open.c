/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:14:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 12:09:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_open(t_cmd *cmd)
{
	if (cmd->hd_r > 2)
	{
		close(cmd->hd_r);
		cmd->hd_r = -1;
	}
	cmd->hd_r = fd_open(cmd->hd_name, O_WRONLY);
	if (cmd->hd_r < 0)
	{
		if (access(cmd->hd_name, F_OK) == 0)
		{
			cmd->hd_r = fd_open(cmd->hd_name, O_WRONLY);
			if (cmd->hd_r < 0)
				return (ft_shell_msg(errno, cmd->hd_name));
		}
		else if (access(cmd->hd_name, O_DIRECTORY) == 0)
			return (ft_shell_msg(EISDIR, cmd->hd_name));
		else
			return (fd_access(cmd->hd_name, 2));
	}
	return (0);
}

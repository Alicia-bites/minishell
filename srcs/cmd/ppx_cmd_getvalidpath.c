/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_getvalidpath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:01:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 08:14:35 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ppx_cmd_getvalidpath(t_cmd *cmd, char **envp)
{
	char	*path;

	path = NULL;
	if (access(cmd->fullcmd[0], F_OK & X_OK) == 0)
		path = ft_strdup(cmd->fullcmd[0]);
	else
	{
		path = ppx_cmd_loop_envp_str(cmd->fullcmd[0], envp, ENV_PATH_NAME);
		if (path)
			return (path);
		path = ppx_cmd_loop_envp(cmd->fullcmd[0], envp);
		if (path)
			return (path);
	}
	if (!path)
	{
		path = ft_strdup(cmd->fullcmd[0]);
		cmd->access = -1;
	}
	else
		cmd->access = 0;
	return (path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getvalidpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:01:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 18:03:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_getvalidpath(t_cmd *cmd)
{
	char	*path;

	path = NULL;
	cmd->access = 0;
	if (access(cmd->fullcmd[0], F_OK & X_OK) == 0)
		path = ft_strdup(cmd->fullcmd[0]);
	else
	{
		path = cmd_loop_envp_str(cmd->fullcmd[0], cmd->env_lst,
				ENV_PATH_NAME);
		if (path)
			return (path);
		path = cmd_loop_envp(cmd->fullcmd[0], cmd->env_lst);
		if (path)
			return (path);
	}
	if (!path)
	{
		path = ft_strdup(cmd->fullcmd[0]);
		cmd->access = -1;
	}
	return (path);
}

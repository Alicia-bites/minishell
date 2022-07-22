/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop_fullpath.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:01:32 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 11:07:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_init_prop_fullpath(t_cmd *cmd)
{
	if (cmd->fullcmd[0] != cmd->fullpath)
	{
		free(cmd->fullcmd[0]);
		cmd->fullcmd[0] = NULL;
		cmd->fullcmd[0] = ft_strdup(cmd->fullpath);
		if (!cmd->fullcmd[0])
			return (ft_panic(-1, __FILE__, ERR_MALLOC));
	}
	return (0);
}

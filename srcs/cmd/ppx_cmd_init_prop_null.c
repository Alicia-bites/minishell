/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_init_prop_null.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:49:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 12:01:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_cmd_init_prop_null(t_cmd *cmd)
{
	cmd->fullcmd = (char **)malloc(sizeof(char *) * 2);
	if (!cmd->fullcmd)
		return (ft_error("cnd_init_prop_init_null", "fullcmd",
				0, ERR_MALLOC));
	cmd->fullcmd[0] = ft_strdup("\0");
	if (!cmd->fullcmd[0])
		return (ft_error("cnd_init_prop_init_null", "fullcmd[0]",
				0, ERR_MALLOC));
	cmd->fullcmd[1] = NULL;
	cmd->fullpath = ft_strdup("\0");
	if (!cmd->fullpath)
		return (ft_error("cnd_init_prop_init_null", "fullpath",
				0, ERR_MALLOC));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop_fullpath.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:01:32 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
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
			return (ft_panic(-1, __func__, ERR_MALLOC));
	}
	return (0);
}

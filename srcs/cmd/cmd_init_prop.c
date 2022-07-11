/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:08:21 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/11 18:36:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_init_prop(t_cmd *cmd, t_list *tok, t_ulist **envp)
{
	if (!cmd)
	{
		ft_panic(-1, ERR_NOOBJ);
		return (1);
	}
	cmd->arg = NULL;
//	if (*arg == '\0')
//	{
//		if (ppx_cmd_init_prop_null(cmd))
//			return (ft_error("cmd_init_prop", "arg null",
//					0, ERR_MALLOC));
//		return (0);
//	}
	cmd->fullcmd = (char **)malloc(sizeof(char *) * (1 + 1));
	if (!cmd->fullcmd)
	{
		ft_panic(-1, ERR_MALLOC);
		return (2);
	}
//	cmd->fullpath = cmd_getvalidpath(cmd, envp);
//	if (cmd->fullcmd[0] != cmd->fullpath)
//	{
//		free(cmd->fullcmd[0]);
//		cmd->fullcmd[0] = NULL;
//		cmd->fullcmd[0] = ft_strdup(cmd->fullpath);
//		if (!cmd->fullcmd[0])
//		{
//			ft_panic(-1, ERR_MALLOC);
//			return (3);
//		}
//	}
	return (0);
}

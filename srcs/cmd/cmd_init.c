/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:07:42 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/11 18:35:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_init(t_list tok, t_ulist **env_lst)
{
	t_cmd	*cmd;

	if (!env_lst)
	{
		ft_panic(-1, ERR_NOOBJ);
		return (NULL);
	}
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
	{
		ft_panic(-1, ERR_MALLOC);
		return (NULL);
	}
	cmd->env_lst = env_lst;
	cmd->arg = NULL;
	cmd->fullcmd = NULL;
	cmd->fullpath = NULL;
	cmd->fd_r = -1;
	cmd->fd_w = -1;
	cmd->access = -1;
//	if (cmd_init_prop(cmd, tok, envp))
//	{
//		free(cmd);
//		cmd = NULL;
//	}
	return (cmd);
}

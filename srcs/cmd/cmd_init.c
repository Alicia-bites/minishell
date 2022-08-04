/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:07:42 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 18:15:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_init(t_list **tok_lst, t_ulist **env_lst)
{
	t_cmd	*cmd;

	if (!env_lst)
		return (ft_panic_null(-1, __FILE__, ERR_NOOBJ));
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	cmd->tok_lst = tok_lst;
	cmd->tok_node = NULL;
	cmd->env_lst = env_lst;
	cmd->toktype = 0;
	cmd->arg = NULL;
	cmd->fullcmd = NULL;
	cmd->fullpath = NULL;
	cmd->hd_name = NULL;
	cmd->hd_r = FD_NOT_INIT;
	cmd->fd_r = FD_NOT_INIT;
	cmd->fd_w = FD_NOT_INIT;
	cmd->pfd_r = FD_NOT_INIT;
	cmd->pfd_w = FD_NOT_INIT;
	cmd->access = -1;
	return (cmd);
}

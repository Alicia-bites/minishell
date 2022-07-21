/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:35:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 18:24:44 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_free(void *content)
{
	t_cmd	*cmd;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	if (cmd->fullcmd)
	{
		ft_free_ptrptr_str(cmd->fullcmd);
		cmd->fullcmd = NULL;
	}
	if (cmd->fullpath)
	{
		free(cmd->fullpath);
		cmd->fullpath = NULL;
	}
	fd_close(cmd);
	free(cmd);
	cmd = NULL;
}

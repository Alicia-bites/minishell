/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:35:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/11 17:57:58 by abarrier         ###   ########.fr       */
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
	cmd_close_fd(content);
	free(cmd);
	cmd = NULL;
}

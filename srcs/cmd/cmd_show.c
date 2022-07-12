/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:10:12 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 13:44:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_show(void *content)
{
	t_cmd	*cmd;
	int		i;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	i = 0;
	printf("toktype: %d\n", cmd->toktype);
	if (cmd->arg)
		printf("arg: %s\n", cmd->arg);
	printf("n_arg: %zu\n", cmd->n_arg);
	if (cmd->fullcmd)
	{
		while (cmd->fullcmd[i])
		{
			printf("fullcmd[%d]: %s\n", i, cmd->fullcmd[i]);
			i++;
		}
	}
	if (cmd->fullpath)
		printf("fullpath: %s\n", cmd->fullpath);
	printf("pfd[0]: %d\tpfd[1]: %d\n", cmd->fd_r, cmd->fd_w);
	printf("access: %d\n", cmd->access);
	printf("%s\n", SEP_P);
}

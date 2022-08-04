/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:10:12 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 18:16:03 by abarrier         ###   ########.fr       */
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
	printf("tok_node: %p\tntoktype: %d\n", cmd->tok_node, cmd->toktype);
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
	if (cmd->hd_name)
		printf("heredoc name: %s\n", cmd->hd_name);
	printf("hd_r: %d\n", cmd->hd_r);
	printf("fd_in: %d\tfd_out: %d\n", cmd->fd_r, cmd->fd_w);
	printf("pfd_in[0]: %d\tpfd_out[1]: %d\n", cmd->pfd_r, cmd->pfd_w);
	printf("access: %d\n%s\n", cmd->access, SEP_P);
}

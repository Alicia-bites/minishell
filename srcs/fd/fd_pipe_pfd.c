/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_pipe_pfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:53:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 18:59:47 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_pipe_pfd(t_ulist *obj, t_cmd *cmd1, t_cmd *cmd2, int n_pipe)
{
	int		pfd[2];
	int		i;

	i = 0;
	while (obj && i < n_pipe)
	{
		cmd1 = (t_cmd *)obj->content;
		cmd2 = (t_cmd *)obj->next->content;
		if (pipe(pfd) < 0)
		{
			ft_shell_msg(errno, "pipe");
			cmd1->pfd_w = -1;
			cmd2->pfd_r = -1;
		}
		else
		{
			cmd1->pfd_w = pfd[1];
			cmd2->pfd_r = pfd[0];
		}
		obj = obj->next;
		i++;
	}
}


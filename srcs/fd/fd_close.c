/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:54:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 18:45:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_close(t_cmd *cmd)
{
	int		res;

	res = 0;
	if (cmd->fd_r > 2)
		res += close(cmd->fd_r);
	if (cmd->fd_w > 2)
		res += close(cmd->fd_w);
	if (cmd->pfd_r > 2)
		res += close(cmd->pfd_r);
	if (cmd->pfd_w > 2)
		res += close(cmd->pfd_w);
	return (res);
}

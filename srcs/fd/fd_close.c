/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:54:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 08:58:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_close(t_ulist *obj)
{
	t_cmd	*cmd;
	int		res;

	res = 0;
	if (!obj)
		return (res);
	cmd = (t_cmd *)obj->content;
	if (cmd->fd_r >= 0)
		res += close(cmd->fd_r);
	if (cmd->fd_w >= 0)
		res += close(cmd->fd_w);
	return (res);
}

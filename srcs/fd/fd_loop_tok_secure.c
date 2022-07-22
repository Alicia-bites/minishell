/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_loop_tok_secure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:23:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 16:11:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_loop_tok_secure(t_cmd *cmd, int res_loop)
{
	if (res_loop)
	{
		fd_close(cmd);
		cmd->fd_r = -1;
		cmd->fd_w = -1;
	}
}

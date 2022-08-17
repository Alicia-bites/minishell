/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_tokfile_link_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:54:43 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 15:36:46 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_tokfile_link_cmd(t_cmd *cmd, int hd, char *hd_name)
{
	if (cmd->hd_r > 2)
	{
		close(cmd->hd_r);
		unlink(cmd->hd_name);
		cmd->hd_r = FD_NOT_INIT;
	}
	hd_create_name_reset(cmd);
	cmd->hd_name = hd_name;
	cmd->hd_r = hd;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_create_name_reset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:23:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 09:24:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_create_name_reset(t_cmd *cmd)
{
	if (cmd->hd_name)
	{
		unlink(cmd->hd_name);
		free(cmd->hd_name);
		cmd->hd_name = NULL;
	}
}

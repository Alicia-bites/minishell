/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:13:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 19:23:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_close(t_cmd *cmd)
{
	int res;

	res = 0;
	if (cmd->hd_r > 2)
		res = close(cmd->hd_r);
	if (cmd->hd_name)
	{
		unlink(cmd->hd_name);
		free(cmd->hd_name);
		cmd->hd_name = NULL;
	}
	return (res);
}

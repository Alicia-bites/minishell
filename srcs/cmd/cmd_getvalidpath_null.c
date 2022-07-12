/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getvalidpath_null.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:52:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 15:53:39 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_getvalidpath_null(t_cmd *cmd)
{
	cmd->fullpath = ft_strdup("\0");
	if (!cmd->fullpath)
	{
		ft_panic(-1, ERR_MALLOC);
		return (NULL);
	}
	return (cmd->fullpath);
}

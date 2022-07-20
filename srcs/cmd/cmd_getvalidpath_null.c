/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getvalidpath_null.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:52:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 14:01:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_getvalidpath_null(t_cmd *cmd)
{
	cmd->fullpath = ft_strdup("\0");
	if (!cmd->fullpath)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	return (cmd->fullpath);
}

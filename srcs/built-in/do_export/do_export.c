/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:20:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 12:47:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export(t_ulist **envp, t_cmd *cmd)
{
	size_t	len_fullcmd;

	if (!cmd)
		return (1);
	len_fullcmd = ft_strstrlen(cmd->fullcmd);
	if (len_fullcmd == 0)
		return (2);
	else if (len_fullcmd == 1)
		ft_lst_func_lst(envp, &do_export_show);
	else if (len_fullcmd > 1)
		do_export_update_lst(envp, &cmd->fullcmd[1]);
	return (0);
}

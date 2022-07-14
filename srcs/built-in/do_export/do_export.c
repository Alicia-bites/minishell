/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:20:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/14 17:31:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd)
		return (1);
	if (ft_strstrlen(cmd->fullcmd) == 0)
		return (2);
	else if (ft_strstrlen(cmd->fullcmd) == 1)
		ft_lst_func_lst(envp, &do_export_show);
	return (0);
}

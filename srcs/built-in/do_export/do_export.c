/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:20:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 14:33:26 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd || cmd->n_arg <= 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->n_arg == 1)
		ft_lst_func_lst(envp, &do_export_show);
	else if (cmd->n_arg > 1 && do_export_update_lst(envp, &cmd->fullcmd[1]))
		return (EXIT_FAILURE);
	return (0);
}

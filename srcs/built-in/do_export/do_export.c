/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:20:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export(t_ulist **envp, t_cmd *cmd)
{
	int	internal_error;

	internal_error = 0;
	if (!cmd || cmd->n_arg <= 0)
		return (ft_panic_value(-1, __func__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->n_arg == 1)
		ft_lst_func_lst(envp, &do_export_show);
	else if (cmd->n_arg >= 2)
	{
		if (cmd->fullcmd[1][0] == '-')
			return (ft_panic_value(-1, __func__, ERR_OPT_INVAL,
					2));
		internal_error = do_export_update_lst(envp, &cmd->fullcmd[1]);
		if (internal_error)
			return (EXIT_FAILURE);
	}
	return (0);
}

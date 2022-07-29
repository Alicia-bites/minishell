/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:22:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 12:56:45 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_env(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->n_arg > 1)
		return (ft_panic_value(-1, __FILE__, ERR_OPT_INVAL,
				EXIT_FAILURE));
	else if (cmd->n_arg == 1)
		ft_lst_func_lst(envp, &do_env_show);
	return (0);
}

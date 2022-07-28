/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:22:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 19:52:02 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd)
{
	int				internal_error;
	long long		exit_return;
	extern t_global	global;

	printf("exit\n");
	internal_error = 0;
	exit_return = 0;
	if (cmd->n_arg == 1)
		exit_return = global.exit_status;
	else if (cmd->n_arg > 1)
		internal_error = ft_str_isll(cmd->fullcmd[1]);
	if (cmd->n_arg == 2 && internal_error == 0)
		exit_return = ft_atoll(cmd->fullcmd[1]);
	rl_clear_history();
	ft_lstclear(cmd->tok_lst);
	ft_lst_free(envp, &env_free);
	ft_lst_free(cmd_lst, &cmd_free);
	if (internal_error > 0)
		exit_return = ft_panic_value(EINVAL, __FILE__, NULL, EINVAL);
	global.exit_status = exit_return;
	exit(exit_return);
	return (exit_return);
}

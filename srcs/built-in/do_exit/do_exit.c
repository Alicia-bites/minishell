/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:22:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/26 19:19:58 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd)
{
	int			internal_error;
	long long	exit_return;

	(void)envp;
	internal_error = 0;
	exit_return = 0;
	if (cmd->n_arg == 1)
		internal_error = 0;
	else
		internal_error = do_exit_check_str(cmd, cmd->fullcmd[1]);
	if (internal_error == 0)
		exit_return = ft_atoll(cmd->fullcmd[1]);
	rl_clear_history();
	ft_lstclear(cmd->tok_lst);
	ft_lst_free(envp, &env_free);
	ft_lst_free(cmd_lst, &cmd_free);
	printf("internal_error: %d\n", internal_error);
	if (internal_error > 0)
	{
		ft_panic(internal_error, __FILE__, NULL);
		exit_return = internal_error;
	}
	exit(exit_return);
	return (exit_return);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:53:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 08:49:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_exit_clear(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd,
		char *err_msg)
{
	extern t_global	g_msl;

	printf("exit\n");
	if (err_msg)
		ft_panic(-1, __FILE__, ERR_ARG_NUM);
	rl_clear_history();
	ft_lstclear(cmd->tok_lst);
	ft_lst_free(envp, &env_free);
	ft_lst_free(cmd_lst, &cmd_free);
	exit(g_msl.exit);
}

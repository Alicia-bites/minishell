/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:53:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 08:48:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_builtin_exit(t_ulist **cmd_lst, t_cmd *cmd, int err_no)
{
	extern t_global	g_msl;

	(void)cmd_lst;
	(void)cmd;
	(void)err_no;
//	rl_clear_history();
//	ft_lstclear(cmd->tok_lst);
//	ft_lst_free(cmd->env_lst, &env_free);
//	ft_lst_free(cmd_lst, &cmd_free);
//	exit(err_no);
	g_msl.exit = errno;
}

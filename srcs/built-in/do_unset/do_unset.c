/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:21:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 15:04:53 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Test
 * export ANTHO=test
 * unset ANTHO ==> Ok, always return(0)
 * unset "ANTHO" ==> Ok, always return(0)
 * unset 'ANTHO' ==> Ok, always return(0)
 * unset $ANTHO
 */
int	do_unset(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->fullcmd[1] != NULL
		&& do_unset_update_lst(envp, &cmd->fullcmd[1]))
		return (EXIT_FAILURE);
	return (0);
}

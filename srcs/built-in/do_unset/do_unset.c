/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:21:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 09:20:40 by abarrier         ###   ########.fr       */
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
	if (!cmd)
		return (1);
	if (ft_strstrlen(cmd->fullcmd) == 0)
		return (2);
	do_unset_update_lst(envp, &do_env_show);
	return (0);
}

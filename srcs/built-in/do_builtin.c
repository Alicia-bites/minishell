/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:56:18 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 15:39:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	else if (ft_strcmp(cmd->fullcmd[0], BUILT_EXIT) == 0)
//		return (do_exit(cmd->env_lst, cmd));
int	do_builtin(t_ulist **cmd_lst, t_cmd *cmd)
{
	int	res;

	if (ft_strcmp(cmd->fullcmd[0], BUILT_CD) == 0)
		return (do_cd(cmd->env_lst, cmd));
	else if (ft_strcmp(cmd->fullcmd[0], BUILT_ECHO) == 0)
		return (do_echo(cmd->env_lst, cmd));
	else if (ft_strcmp(cmd->fullcmd[0], BUILT_ECHO_N) == 0)
		return (do_echo_n(cmd->env_lst, cmd));
	else if (ft_strcmp(cmd->fullcmd[0], BUILT_ENV) == 0)
		return (do_env(cmd->env_lst, cmd));
	else if (ft_strcmp(cmd->fullcmd[0], BUILT_EXPORT) == 0)
		return (do_export(cmd->env_lst, cmd));
	else if (ft_strcmp(cmd->fullcmd[0], BUILT_PWD) == 0)
		return (do_pwd());
	else if (ft_strcmp(cmd->fullcmd[0], BUILT_UNSET) == 0)
		return (do_unset(cmd->env_lst, cmd));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:22:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/01 17:35:49 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_env(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd)
		return (1);
	if (ft_strstrlen(cmd->fullcmd) == 0)
		return (2);
	else if (ft_strstrlen(cmd->fullcmd) == 1) //case: env
		ft_lst_func_lst(envp, &do_env_show);
	else if (ft_strstrlen(cmd->fullcmd) >= 2 && ft_strchr(cmd->arg, ENV_SEP)) //case: env NAME1=value
	{
		do_env_update_lst(envp, &cmd->fullcmd[1]);
		ft_lst_func_lst(envp, &do_env_show);
	}
	return (0);
}

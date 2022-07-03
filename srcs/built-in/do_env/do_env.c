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

#include "../../includes/minishell.h"

int	do_env(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd)
		return (1);
	if (ft_strstrlen(cmd->fullcmd) == 0)
		return (2);
	else if (ft_strstrlen(cmd->fullcmd) == 1) //case: env
		ft_lst_func_lst(envp, &do_env_show);
	else if (ft_strstrlen(cmd->fullcmd) => 2 && ft_strchr(cmd->fullcmd, ENV_SEP)) //case: env NAME1=value
		printf("TO BE DONE WITH SPECIFIC CASE\n"
		"1. Update the list and UNDO the modification to the previous value\n"
		"2. Create the env variable and display the whole list and REMOVE the new env from the list at the end of the process\n");
	else
		do_env_update_lst(envp, &cmd->fullcmd[1]);
	return (0);
}

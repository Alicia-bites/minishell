/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:16:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/20 13:54:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Update variable PWD and OLDPWD export and env list when changing directory
 * 
 */
int	do_cd(t_ulist **envp, t_cmd *cmd)
{
	size_t	len_cmd;

	if (!cmd)
		return (1);
	len_cmd = ft_strstrlen(cmd->fullcmd);
	if (len_cmd == 1)
		do_cd_home(envp);
	else if (len_cmd > 1)
		return (ft_panic(-1, __FILE__, ERR_ARG));
	return (0);
}

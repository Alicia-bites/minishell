/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:16:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 14:51:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Update variable PWD and OLDPWD export and env list when changing directory
 * 
 */
int	do_cd(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->n_arg > 1)
		return (ft_panic_value(-1, __FILE__, ERR_ARG, EXIT_FAILURE));
	else if (cmd->n_arg == 1 && do_cd_home(envp))
		return (EXIT_FAILURE);
	return (0);
}

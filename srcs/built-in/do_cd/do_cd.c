/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:16:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 11:11:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* n_arg is the total of argument including the command exit itself
 * @IF n_arg == 1
 * ==> change the active directory by the HOME
 * ==> message: 
 * ==> return: 0
 *
 * @ELSE IF n_arg >= 3
 * 	@IF the first argument start with '-'
 * 	==> do nothing
 * 	==> message: invalid option
 * 	==> return: 2
 *
 * 	@ELSE
 * 	==> do nothing
 * 	==> message: too many arguments
 * 	==> return: 1
 * @ELSE
 * ==> change the active directory by the speficied one
 * ==> message: if error, use ft_panic with errno
 * ==> return = 1
 */
int	do_cd(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __func__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->n_arg >= 2)
	{
		if (only_this_in_str(cmd->fullcmd[1], '\'')
			|| only_this_in_str(cmd->fullcmd[1], '\''))
			return (0);
		if (cmd->fullcmd[1][0] == '-')
			return (ft_panic_value(-1, __func__, ERR_OPT_INVAL, 2));
		else if (cmd->n_arg >= 3)
			return (ft_panic_value(-1, __func__, ERR_ARG_N, 1));
		else
			return (do_cd_change_dir(envp, cmd));
	}
	else if (cmd->n_arg == 1 && do_cd_home(envp))
		return (EXIT_FAILURE);
	return (0);
}

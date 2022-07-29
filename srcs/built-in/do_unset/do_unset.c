/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:21:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 12:55:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* n_arg is the total of argument including the command exit itself
 * @IF n_arg == 1
 * ==> do nothing
 * ==> message: N/A
 * ==> return: 0
 *
 * @ELSE IF n_arg >= 2
 * 	@IF the first argument is does not start by '-'
 * 		@LOOP FOR EACH ARG
 * 			@IF arg contains forbidden charset
 * 			==> do nothing
 * 			==> message: not a valid identifier
 * 			==> return: 1
 *
 * 			@ELSE
 * 			==> remove the env variable
 * 			==> message: N/A
 * 			==> return: 0
 *
 * 	@ELSE
 *	==> no nothing
 *	==> message: invalid option
 *	==> return = 2
 */
int	do_unset(t_ulist **envp, t_cmd *cmd)
{
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	else if (cmd->n_arg >= 2)
	{
		if (cmd->fullcmd[1][0] == '-')
			return (ft_panic_value(-1, __FILE__, ERR_OPT_INVAL, 2));
		else
			return (do_unset_update_lst(envp, &cmd->fullcmd[1]));
	}
	return (0);
}

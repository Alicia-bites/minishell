/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:22:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:49:38 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* n_arg is the total of argument including the command exit itself
 * @IF n_arg == 1
 * ==> exit the program
 * ==> display exit: YES
 * ==> message: N/A
 * ==> return: return value of the last executed command
 *
 * @ELSE IF n_arg >= 2
 * 	@IF the first argument is numeric
 * 		@IF n_arg == 2
 * 		==> exit the program
 *		==> display exit: YES
 * 		==> message: N/A
 * 		==> return: argument value
 *
 * 		@ELSE
 * 		==> do not exit the program
 *		==> display exit: NO
 * 		==> message: too many arguments
 * 		==> return: 1
 * 	@ELSE
 *	==> exit the program
 *	==> display exit: YES
 *	==> message: numeric argument required
 *	==> return = 2
 */
int	do_exit(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd)
{
	extern t_global	g_msl;

	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	if (cmd->n_arg == 1)
		do_exit_clear(envp, cmd_lst, cmd, NULL);
	else
	{
		if (ft_str_isdigit(cmd->fullcmd[1]) && ft_str_isll(cmd->fullcmd[1]))
		{
			if (cmd->n_arg == 2)
			{
				g_msl.exit = ft_atoll(cmd->fullcmd[1]);
				do_exit_clear(envp, cmd_lst, cmd, NULL);
			}
			else
				return (ft_panic_value(-1, __FILE__, ERR_ARG_N, 1));
		}
		else
		{
			g_msl.exit = 2 ;
			do_exit_clear(envp, cmd_lst, cmd, "error");
		}
	}
	return (0);
}

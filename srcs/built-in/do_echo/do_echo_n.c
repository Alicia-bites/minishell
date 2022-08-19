/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:56:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 08:05:31 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* function do_echo_get_fullcmd_index will get the correct index of fullcmd
 * example:
 * cmd				| i tok	| i fullcmd
 * -------------------------------------------------------------------------
 * echo				| 0	| 0
 * echo -n			| 1	| 1
 * echo > f1 hello		| 0	| 0
 * echo > fi -n hello		| 3	| 1
 *
 * then this fullcmd index is shifted to +1 to start to print the argument
 * to be printed
 * example:
 * cmd				| i fullcmd	| i p arg	| 1st p arg
 * -------------------------------------------------------------------------
 * echo				| 0		| 1		| NULL
 * echo -n			| 1 + 1		| 2		| NULL
 * echo > f1 hello		| 0 + 1		| 1		| hello
 * echo > fi -n hello		| 1 + 1		| 2		| hello
 */
int	do_echo_n(t_cmd *cmd, int index)
{
	int	res;
	int	i;

	res = 0;
	if (!index)
		return (ft_panic_value(-1, __func__, ERR_ECHO_FAILURE,
				EXIT_FAILURE));
	if (cmd->n_arg == 1)
		return (0);
	i = do_echo_get_fullcmd_index(cmd, index);
	if (i <= 0)
		i = 1;
	else
		i++;
	while (i < (int)(cmd->n_arg))
	{
		res += printf("%s ", cmd->fullcmd[i]);
		i++;
	}
	return (res);
}

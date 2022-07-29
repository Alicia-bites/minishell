/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:56:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 13:10:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_echo_n(t_ulist **envp, t_cmd *cmd, int index)
{
	int	res;
	int	i;

	res = 0;
	if (!index)
		return (ft_panic_value(-1, __FILE__, ERR_ECHO_FAILURE, EXIT_FAILURE));
	i = index;
	if (cmd->n_arg == 1)
		return (0);
	while (i < (cmd->n_arg -1))
	{
		res += printf("%s ", cmd->fullcmd[i]);
		i++;
	}
	res += printf("%s", cmd->fullcmd[i]);
	if (res <= 0)
		return (1);
	else
		return (0);
}

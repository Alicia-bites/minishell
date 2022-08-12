/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:56:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:35:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_echo_n(t_ulist **envp, t_cmd *cmd, int index)
{
	int	res;
	int	i;

	res = 0;
	if (!index)
		return (ft_panic_value(-1, __FILE__, ERR_ECHO_FAILURE,
				EXIT_FAILURE));
	if (cmd->n_arg == 1)
		return (0);
	i = index - cmd->tok_node->index;
	while (i < (cmd->n_arg -1))
	{
		res += printf("%s ", cmd->fullcmd[i]);
		i++;
	}
	res += printf("%s", cmd->fullcmd[i]);
	return (res);
}

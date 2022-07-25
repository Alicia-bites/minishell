/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:56:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/28 11:25:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_echo_n(t_ulist **envp, t_cmd *cmd)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
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

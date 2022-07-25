/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:56:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 12:10:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_echo(t_ulist **envp, t_cmd *cmd)
{
	int	i;
	
	i = 1;
	while (cmd->fullcmd[i])
		printf("%s", cmd->fullcmd[i++]);
	printf("\n");
	return (0);
}

int	do_echo_n(t_ulist **envp, t_cmd *cmd)
{
	int	i;
	
	i = 1;
	while (cmd->fullcmd[i])
		printf("%s", cmd->fullcmd[i++]);
	return (0);
}

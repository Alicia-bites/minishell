/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop_fullcmd_null.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:49:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*cmd_init_prop_fullcmd_null(t_list *tok, t_cmd *cmd)
{
	cmd->fullcmd = (char **)malloc(sizeof(char *) * 2);
	if (!cmd->fullcmd)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	cmd->fullcmd[0] = ft_strdup("\0");
	if (!cmd->fullcmd[0])
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	cmd->fullcmd[1] = NULL;
	return (tok->next);
}

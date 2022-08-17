/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_loop_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:07:56 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 09:24:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 *
 * @PARAM:
 * void *content: content of the command node
 *
 * @RETURN:
 * N/A
 */
t_cmd	*fd_init_tokfile_loop_cmd(t_ulist **cmd_lst, t_list *tokcmd)
{
	t_ulist	*obj;
	t_cmd	*cmd;

	if (!cmd_lst || !*cmd_lst)
		return (NULL);
	obj = *cmd_lst;
	while (obj)
	{
		cmd = (t_cmd *)obj->content;
		if (cmd->tok_node == tokcmd)
			return (cmd);
		obj = obj->next;
	}
	return (NULL);
}

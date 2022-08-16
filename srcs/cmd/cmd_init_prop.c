/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:08:21 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/16 18:21:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*cmd_init_prop(t_list *tok, t_cmd *cmd)
{
	t_list	*obj;

	if (!tok || !cmd)
		return (ft_panic_null(-1, __FILE__, ERR_NOOBJ));
	obj = tok;
	cmd->tok_node = obj;
	cmd->toktype = obj->toktype;
	cmd->n_arg = cmd_init_prop_n_arg(obj);
	if (cmd->n_arg > 0)
		obj = cmd_init_prop_fullcmd(obj, cmd);
	else
		obj = cmd_init_prop_fullcmd_null(obj, cmd);
	if (!cmd->fullcmd)
		return (NULL);
	if (cmd->toktype == TOK_CMD && cmd->n_arg > 0)
		cmd->fullpath = cmd_getvalidpath(cmd);
	else if (cmd->toktype == TOK_CMD)
		cmd->fullpath = cmd_getvalidpath_null(cmd);
	if (cmd->toktype == TOK_CMD && cmd_init_prop_fullpath(cmd))
	{
		cmd_free(cmd);
		return (NULL);
	}
	cmd_init_prop_access(cmd);
	return (obj);
}

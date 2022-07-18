/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:08:21 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 15:59:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*cmd_init_prop(t_list *tok, t_cmd *cmd)
{
	t_list	*obj;

	if (!tok || !cmd)
	{
		ft_panic(-1, ERR_NOOBJ);
		return (NULL);
	}
	obj = tok;
	cmd->toktype = obj->toktype;
	cmd->n_arg = cmd_init_prop_n_arg(obj, cmd);
	if (cmd->n_arg > 0)
		obj = cmd_init_prop_fullcmd(obj, cmd);
	else
		obj = cmd_init_prop_fullcmd_null(obj, cmd);
	if (!cmd->fullcmd)
		return (NULL);
	if (cmd->toktype == TOK_CMD && cmd->n_arg > 0)
		cmd->fullpath = cmd_getvalidpath(cmd);
	else
		cmd->fullpath = cmd_getvalidpath_null(cmd);
	return (obj);
}
//	if (*arg == '\0')
//	{
//		if (ppx_cmd_init_prop_null(cmd))
//			return (ft_error("cmd_init_prop", "arg null",
//					0, ERR_MALLOC));
//		return (0);
//	}
//	cmd->fullcmd = (char **)malloc(sizeof(char *) * (1 + 1));
//	if (!cmd->fullcmd)
//	{
//		ft_panic(-1, ERR_MALLOC);
//		return (2);
//	}
//	cmd->fullpath = cmd_getvalidpath(cmd, envp);
//	if (cmd->fullcmd[0] != cmd->fullpath)
//	{
//		free(cmd->fullcmd[0]);
//		cmd->fullcmd[0] = NULL;
//		cmd->fullcmd[0] = ft_strdup(cmd->fullpath);
//		if (!cmd->fullcmd[0])
//		{
//			ft_panic(-1, ERR_MALLOC);
//			return (3);
//		}
//	}

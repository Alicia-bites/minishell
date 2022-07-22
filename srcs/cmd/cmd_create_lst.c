/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:45:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 13:01:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_create_lst(t_list **tok_lst, t_ulist **env_lst, t_ulist **cmd_lst)
{
	t_list	*obj;
	t_cmd	*cmd;
	int		j;

	obj = *tok_lst;
	while (obj)
	{
		cmd = NULL;
		if (obj->toktype == TOK_BUILTIN || obj->toktype == TOK_CMD)
		{
			cmd = cmd_init(tok_lst, env_lst);
			if (!cmd)
				return (1);
			obj = cmd_init_prop(obj, cmd);
			if (!ft_lst_append(cmd_lst, (void *)cmd))
			{
				cmd_free(cmd);
				return (2);
			}
		}	
		else
			obj = obj->next;
	}
	return (0);
}

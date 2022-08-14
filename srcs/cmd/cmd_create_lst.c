/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:45:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 16:51:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * populate command list according to token list and minishell environment
 * list
 *
 * @PARAM:
 * t_list **tok_lst: token list
 * t_ulist **env_lst: minishell environment list
 * t_ulist **cmd_lst: command list
 *
 * @RETURN:
 * 0: ok
 * > 0: error
 */
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
				return (EXIT_FAILURE);
			obj = cmd_init_prop(obj, cmd);
			if (!ft_lst_append(cmd_lst, (void *)cmd))
			{
				cmd_free(cmd);
				return (EXIT_FAILURE);
			}
		}	
		else
			obj = obj->next;
	}
	return (0);
}

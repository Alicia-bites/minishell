/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop_fullcmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:32:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @brief@ Set command properties
 *
 * @param@ t_list *tok: token from token list | t_cmd *cmd: active command
 *
 * @return@ t_list * | NULL: error, !=NULL: address of the token which
 * is not relative to the fullcmd, used for the command loop
 *
 * Example: grep -RiEn 'toto' | wc > file1
 * s[0] = "grep"	--> toktype = 1 --> START - fullcmd[0]
 * s[1] = " "		--> toktype = 2 --> Not added into fullcmd
 * s[2] = "-RiEn"	--> toktype = 4 --> fullcmd[1]
 * s[3] = " "		--> toktype = 2 --> Not added into fullcmd
 * s[4] = "'toto'"	--> toktype = 4 --> fullcmd[2]
 * s[5] = " "		--> toktype = 2 --> Not added into fullcmd
 * s[6] = "| "		--> toktype = ? --> STOP - return this address
 * s[7] = " "		--> toktype = 2
 * s[8] = "wc"		--> toktype = 1
 * s[9] = " "		--> toktype = 2
 * s[10] = ">"		--> toktype = ?
 * s[11] = " "		--> toktype = 2
 * s[12] = "file1"	--> toktype = ?
 */
t_list	*cmd_init_prop_fullcmd(t_list *tok, t_cmd *cmd)
{
	t_list	*obj;
	int		i;

	cmd->fullcmd = (char **)malloc(sizeof(char *) * (cmd->n_arg + 1));
	if (!cmd->fullcmd)
		return (ft_panic_null(-1, __func__, ERR_NOOBJ));
	cmd->fullcmd[0] = ft_strdup(tok->token);
	obj = tok->next;
	i = 1;
	while (obj && !(obj->toktype == TOK_PIPE))
	{
		if (obj->toktype == TOK_ARG)
		{
			cmd->fullcmd[i] = ft_strdup(obj->token);
			i++;
		}
		obj = obj->next;
	}
	cmd->fullcmd[i] = NULL;
	return (obj);
}

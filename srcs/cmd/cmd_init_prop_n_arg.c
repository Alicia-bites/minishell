/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop_n_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:36:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/19 15:24:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @brief@ Calculate total of object for a full command according to
 * toktype 1, 2, 4
 *
 * @param@ t_list *tok: token from token list | t_cmd *cmd: active command
 *
 * @return@ size_t | >= 0: total of object (at minimum, the return = 1)
 * Example: grep -RiEn 'toto' | wc > file1
 * s[0] = "grep"	--> toktype = 1 --> START - fullcmd[0]
 * s[1] = " "		--> toktype = 2 --> Not added into fullcmd
 * s[2] = "-RiEn"	--> toktype = 4 --> fullcmd[1]
 * s[3] = " "		--> toktype = 2 --> Not added into fullcmd
 * s[4] = "'toto'"	--> toktype = 4 --> fullcmd[2]
 * s[5] = " "		--> toktype = 2 --> Not added into fullcmd
 * s[6] = "| "		--> toktype = ? --> STOP
 * s[7] = " "		--> toktype = 2
 * s[8] = "wc"		--> toktype = 1
 * s[9] = " "		--> toktype = 2
 * s[10] = ">"		--> toktype = ?
 * s[11] = " "		--> toktype = 2
 * s[12] = "file1"	--> toktype = ?
 */
size_t	cmd_init_prop_n_arg(t_list *tok, t_cmd *cmd)
{
	t_list	*obj;
	size_t	res;

	obj = tok->next;
	res = 1;
	while (obj && !(obj->toktype == TOK_PIPE))
	{
		if (obj->toktype == 4)
			res++;
		obj = obj->next;
	}
	return (res);
}

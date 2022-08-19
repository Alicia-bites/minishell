/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo_get_fullcmd_index.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 07:37:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 08:08:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * function do_echo_get_fullcmd_index will get the correct index of fullcmd
 * example:
 * cmd				| i tok	| i fullcmd
 * -------------------------------------------------------------------------
 * echo				| 0	| 0
 * echo -n			| 1	| 1
 * echo > f1 hello		| 0	| 0
 * echo > fi -n hello		| 3	| 1
 *
 * @PARAM:
 * t_cmd *cmd: command node
 * int index: index from token list
 *
 * @RETURN:
 * >= 0: index to be sued for cmd->fullcmd[i]
 */
int	do_echo_get_fullcmd_index(t_cmd *cmd, int index)
{
	t_list	*tok;
	int	i;

	tok = cmd->tok_node;
	i = 0;
	while (tok)
	{
		if (tok->index == index)
			return (i);
		if (tok->toktype == TOK_ARG)
			i++;
		tok = tok->next;
	}
	return (i);
}

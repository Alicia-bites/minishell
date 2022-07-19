/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 14:30:11 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is built-in a token whose name (char *token_list->token) is found in tab of
// char * built_ins (char **built_ins)
int	is_built_in(t_list **token_list)
{
	int	i;
	char **built_ins;
	extern t_global	global;

	built_ins = store_built_ins();
	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp((*token_list)->token, built_ins[i++]))
		{
			(*token_list)->toktype = TOK_BUILTIN;
			free(built_ins);
			global.seen_tok_cmd = 1;
			return (1);
		}
	}
	free(built_ins);
	return (0);
}

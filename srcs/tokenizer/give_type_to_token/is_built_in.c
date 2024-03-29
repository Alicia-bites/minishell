/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 16:41:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is built-in a token whose name (char *token_list->token) is found in tab of
// char * built_ins (char **built_ins)
int	is_built_in(t_list **token_list, int *seen_cmd)
{
	int				i;
	char			**built_ins;

	if ((*token_list)->prev && (*token_list)->prev->toktype == TOK_BUILTIN)
		return (0);
	if ((*token_list)->prev && ((*token_list)->prev->toktype == TOK_DL_REDIR
			|| (*token_list)->prev->toktype == TOK_DR_REDIR
			|| (*token_list)->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->toktype == TOK_R_REDIR))
		return (0);
	built_ins = store_built_ins();
	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp((*token_list)->token, built_ins[i++]))
		{
			(*token_list)->toktype = TOK_BUILTIN;
			free(built_ins);
			*seen_cmd = 1;
			return (1);
		}
	}
	free(built_ins);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_toktype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/05 17:03:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_toktype(t_chartype *input_list, t_list **token_list)
{
	t_list	*it;
	int		i;
	char 	**built_ins;
	
	it = *token_list;
	built_ins = store_built_ins();
	while (*token_list)
	{
		i = 0;
		while (i < 8)
		{
			if (!ft_strcmp((*token_list)->token, built_ins[i++]))
			{
				(*token_list)->toktype = TOK_BUILTIN;
				break ;				
			}
		}
		if (is_operator((*token_list)->token))
		{
			(*token_list)->toktype = is_operator((*token_list)->token);				
		}
		else if (!only_space_in_str((*token_list)->token))
		{
			(*token_list)->toktype = TOK_SPACE;
		}
		//aller chercher cette fonction dans pipex
		// else if (ft_iscommand((*token_list)->token))
		// {
			// (*token_list)->toktype = "command";
		// }
		else if ((*token_list)->index >= 2
			&& (*token_list)->prev->prev->toktype == TOK_BUILTIN
			&& (ft_strcmp((*token_list)->token, "$")
			/*|| (*token_list)->prev->toktype == TOK_CMD*/))
			(*token_list)->toktype = TOK_ARG;				
		else if ((*token_list)->index >= 3)
		{
			if (!(ft_strcmp((*token_list)->prev->token, "$")
			&& (*token_list)->prev->prev->prev->toktype == TOK_BUILTIN)
				/*|| (*token_list)->prev->toktype == TOK_CMD*/)
			(*token_list)->toktype = TOK_ARG;	
		}
		*token_list = (*token_list)->next;
	}
	*token_list = it;
	// print_lst(*token_list);
}
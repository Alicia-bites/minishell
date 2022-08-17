/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_presence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:24:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 14:54:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_back_to_beginning_of_list(t_list **token_list)
{
	while ((*token_list)->prev)
		(*token_list) = (*token_list)->prev;
}

static void	find_token_in_list(char *token, t_list **token_list)
{
	while (token_list)
	{
		if (!ft_strcmp(token, (*token_list)->token))
			if ((*token_list)->toktype != TOK_NOT_OP)
				return ;
		(*token_list) = (*token_list)->next;
	}
}

void	check_operator_presence(char *token, t_list **token_list)
{
	find_token_in_list(token, token_list);
	if (found_operator((*token_list)->token))
		(*token_list)->toktype = TOK_NOT_OP;
	go_back_to_beginning_of_list(token_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:19:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/26 18:25:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_back_to_head(t_list **token_list)
{
	if ((*token_list)->prev)
	{
		while ((*token_list)->prev)
			(*token_list) = (*token_list)->prev;
	}
}

int	is_export_special(t_list *token_list)
{
	if (token_list->index >= 2)
	{
		if (!ft_strcmp(token_list->prev->prev->token, "export")
			&& seen_equal_last(token_list->prev->token)
			&& !only_space_in_str(token_list->token))
			return (1);
	}
	return (0);
}

int	only_spaces_in_list(t_list *token_list)
{
	while (token_list)
	{
		if (only_space_in_str(token_list->token))
			return (0);
		token_list = token_list->next;
	}
	return (1);
}

void	delete_spaces(t_list **token_list)
{
	t_list	*tmp;

	if (only_spaces_in_list(*token_list))
	{
		(*token_list)->toktype = TOK_CMD;
		return ;
	}
	tmp = (*token_list);
	while ((*token_list))
	{
		while (*token_list && !only_space_in_str((*token_list)->token)
			&& !is_export_special((*token_list)))
			(*token_list) = ft_lst_delnode(*token_list, &delete_content);
		if (!*token_list)
			(*token_list) = tmp;
		(*token_list) = (*token_list)->next;
	}
	go_back_to_head(&tmp);
	(*token_list) = tmp;
}

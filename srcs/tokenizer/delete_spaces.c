/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:19:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 16:08:15 by amarchan         ###   ########.fr       */
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

void	delete_content(t_list *token_list)
{
	free(token_list->token);
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

void	delete_spaces(t_list **token_list)
{
	t_list	*tmp;

	tmp = (*token_list);
	while ((*token_list))
	{
		if (!only_space_in_str(tmp->token)
			&& !is_export_special((*token_list)))
			tmp = tmp->next;
		if (!only_space_in_str((*token_list)->token)
			&& !is_export_special((*token_list)))
			(*token_list) = ft_lst_delnode(*token_list, &delete_content);
		if (!*token_list)
			(*token_list) = tmp;
		(*token_list) = (*token_list)->next;
	}
	go_back_to_head(&tmp);
	(*token_list) = tmp;
}

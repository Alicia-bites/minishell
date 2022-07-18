/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:19:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 17:20:09 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

static void	go_back_to_head(t_list **token_list)
{
	if ((*token_list)->prev)
	{
		while ((*token_list)->prev)
			(*token_list) = (*token_list)->prev;
	}
}

static void	delete_content(t_list *token_list)
{
	free(token_list->token);
}

void	delete_spaces(t_list **token_list)
{
	t_list	*tmp;

	tmp = (*token_list);
	while ((*token_list))
	{
		if (!only_space_in_str(tmp->token))
			tmp = tmp->next;
		if(!only_space_in_str((*token_list)->token))
			(*token_list) = ft_lst_delnode(*token_list, &delete_content);
		if (!*token_list)
			(*token_list) = tmp;
		(*token_list) = (*token_list)->next;
	}
	go_back_to_head(&tmp);
	(*token_list) = tmp;
}

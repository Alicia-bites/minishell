/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_export_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:47:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 17:48:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	built_new_token_list(t_list **token_list)
{
	if ((*token_list)->next)
	{
		(*token_list)->token
			= ft_strjoin((*token_list)->token, (*token_list)->next->token);
		*token_list = ft_lst_delnode((*token_list)->next, &delete_content);
	}
}

void	concatenate_export_args(t_list **token_list)
{
	t_list	*tmp;
	int		i;

	tmp = *token_list;
	while (*token_list)
	{
		if (!ft_strcmp((*token_list)->token, "export"))
		{
			if ((*token_list)->next)
				*token_list = (*token_list)->next;
			if (seen_equal_last((*token_list)->token))
				built_new_token_list(token_list);
		}
		if (*token_list)
			*token_list = (*token_list)->next;
	}
	*token_list = tmp;
}
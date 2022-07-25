/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 16:07:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	seen_equal_last(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '=' && (i == ft_strlen(token) - 1))
			return (1);
		i++;
	}
	return (0);
}

void	built_new_token_list(t_list **token_list)
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

void	tokenize(t_chartype *input_list, t_list **token_list)
{
	get_chartype(&input_list);
	get_token(input_list, token_list);
	delete_spaces(token_list);
	get_toktype(token_list);
	concatenate_export_args(token_list);
}

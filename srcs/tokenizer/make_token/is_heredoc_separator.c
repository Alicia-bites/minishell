/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc_separator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:56:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 11:08:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_heredoc_separator(t_list *token_list)
{
	t_list	*iterator;

	if (!token_list)
		return (0);
	iterator = token_list;
	while (iterator->next)
		iterator = iterator->next;
	if (iterator->index == 0)
		return (0);
	if (iterator && !ft_strcmp(iterator->token, "<<"))
		return (1);
	if (iterator && iterator->prev
		&& !only_space_in_str(iterator->token)
		&& !ft_strcmp(iterator->prev->token, "<<"))
		return (1);
	return (0);
}
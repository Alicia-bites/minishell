/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:01:12 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 15:35:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_dollar(t_expanded **lst)
{
	t_expanded	*iterator;
	t_expanded	*prev;

	iterator = *lst;
	prev = NULL;
	while (iterator)
	{
		prev = iterator;
		iterator = iterator->next;
		if (prev->expanded && ft_strcmp(prev->expanded, "smbash"))
			free(prev->expanded);
		free(prev);
	}
	*lst = NULL;
}

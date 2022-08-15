/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:01:12 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 09:18:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_dollar(t_expanded **lst)
{
	t_expanded	*iterator;
	t_expanded	*prev;

	if (!*lst)
		return ;
	iterator = *lst;
	prev = NULL;
	while (iterator)
	{
		prev = iterator;
		iterator = iterator->next;
		if (prev->expanded && ft_strcmp(prev->expanded, "smbash")
			&& prev->expanded[0] != '\0')
			free(prev->expanded);
		free(prev);
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:01:12 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/13 15:24:47 by amarchan         ###   ########.fr       */
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
		if (prev->expanded)
			free(prev->expanded);
		free(prev);
	}
	*lst = NULL;
}

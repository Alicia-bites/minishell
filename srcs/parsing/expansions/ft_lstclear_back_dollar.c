/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_back_dollar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:09 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/11 16:21:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//clear the list starting from the LAST element
void	ft_lstclear_back_dollar(t_expanded **lst)
{
	t_expanded	*iterator;
	t_expanded	*prev;

	if (*lst == NULL)
		return ;
	iterator = *lst;
	prev = NULL;
	while (iterator->prev)
	{
		prev = iterator;
		iterator = iterator->prev;
		if (prev->expanded)
			free(prev->expanded);
		free(prev);
	}
	free(iterator);
	*lst = NULL;
}

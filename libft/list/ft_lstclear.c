/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:19:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/11 16:15:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst)
{
	t_list	*iterator;
	t_list	*prev;
	
	iterator = *lst;
	prev = NULL;
	while (iterator)
	{
		prev = iterator;
		iterator = iterator->next;
		if (prev->token)
			free(prev->token);			
		free(prev);
	}
	*lst = NULL;
}

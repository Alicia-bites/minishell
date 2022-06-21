/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:19:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 18:31:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "../includes/minishell.h"

void	ft_lstclear(t_list **lst)
{
	// extern	g_global;
	t_list	*iterator;
	t_list	*prev;
	
	// g_global->lst_cleared = 1;
	iterator = *lst;
	prev = NULL;
	while (iterator)
	{
		prev = iterator;
		iterator = iterator->next;
		free(prev);
	}
	*lst = NULL;
}

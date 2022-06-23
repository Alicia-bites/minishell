/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:09:02 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 10:23:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Create a linked list of inputs with indexes
t_list	*create_list(char *str, int i, e_toktype toktype)
{
	static t_list			*lst;
	t_list					*new;

	// if (lst->next)
		// printf("lst->next->token %s\n", lst->next->token);
	if (i == 0)
		lst = ft_lstnew(str, i, toktype);
	else
	{
		new = ft_lstnew(str, i, toktype);
		ft_lstadd_back(&lst, new);
	}
	// printf("i = %d\n", i);
	// printf("lst->token %s\n", lst->token);	
	return (lst);
}
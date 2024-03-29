/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:09:02 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 15:48:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create a linked list of inputs with indexes
t_list	*create_list(char *str, int i, t_toktype toktype)
{
	static t_list			*lst;
	t_list					*new;

	if (i == 0)
		lst = ft_lstnew(str, i, toktype);
	else
	{
		new = ft_lstnew(str, i, toktype);
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}

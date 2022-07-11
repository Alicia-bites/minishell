/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dollar_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:46:42 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 19:53:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create a linked list of inputs with indexes
t_expanded	*create_dollar_list(char *str, int index)
{
	static t_expanded			*lst;
	t_expanded					*new;

	if (index == 0)
		lst = ft_lstnew_dollar(str, index);
	else
	{
		new = ft_lstnew_dollar(str, index);
		ft_lstadd_back_dollar(&lst, new);
	}
	return (lst);
}
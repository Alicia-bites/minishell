/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:24 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 19:50:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_expanded	*ft_lstnew_dollar(char *str, int i)
{
	t_expanded	*elt;

	elt = malloc(sizeof(t_expanded));
	if (!elt)
		return (NULL);
	elt->index = i;
	elt->expanded = str;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}
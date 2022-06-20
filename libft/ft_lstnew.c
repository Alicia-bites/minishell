/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:23:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 12:52:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *str, int i)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->token = str;
	elt->index = i;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

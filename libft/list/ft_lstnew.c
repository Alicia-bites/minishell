/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:23:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 15:40:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstnew(char *str, int i, t_toktype toktype)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->index = i;
	elt->token = str;
	elt->toktype = toktype;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

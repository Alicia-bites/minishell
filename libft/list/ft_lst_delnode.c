/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:05:02 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 17:08:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_lst_delnode(t_list *obj, void (*f)(t_list *))
{
	t_list	*prev;
	t_list	*next;

	if (!obj)
	{
		ft_panic(-1, ERR_NOOBJ);
		return (NULL);
	}
	prev = obj->prev;
	next = obj->next;
	if (prev)
	{
		prev->next = next;
		if (next)
			next->prev = prev;
	}
	else if (next)
		next->prev = NULL;
	if (f)
		(f)(obj);
	free(obj);
	obj = NULL;
	return (next);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:05:02 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	update_index(t_list **next, t_list *obj)
{
	t_list	*iterator;

	iterator = (*next);
	while ((*next))
	{
		(*next)->index = obj->index++;
		(*next) = (*next)->next;
	}
	(*next) = iterator;
}

static void	join_broken_list(t_list **prev, t_list **next, t_list *obj)
{
	(*prev)->next = (*next);
	if ((*next))
	{
		(*next)->prev = (*prev);
		update_index(next, obj);
	}
}

t_list	*ft_lst_delnode(t_list *obj, void (*f)(t_list *))
{
	t_list	*prev;
	t_list	*next;

	if (!obj)
		return (ft_panic_null(-1, __func__, ERR_NOOBJ));
	prev = obj->prev;
	next = obj->next;
	if (prev)
		join_broken_list(&prev, &next, obj);
	else if (next)
	{
		next->index = 0;
		update_index(&next, obj);
		next->prev = NULL;
	}
	if (f)
		(f)(obj);
	free(obj);
	obj = NULL;
	return (next);
}

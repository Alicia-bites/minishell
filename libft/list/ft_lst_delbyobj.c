/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delbyobj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:31:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:25:15 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_delbyobj(t_ulist *obj, void (*f)(void *))
{
	t_ulist	*prev;
	t_ulist	*next;

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
		(f)(obj->content);
	free(obj);
	obj = NULL;
	return (next);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delbyobj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:31:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_delbyobj(t_ulist *obj, void (*f)(void *))
{
	t_ulist	*prev;
	t_ulist	*next;

	if (!obj)
		return (ft_panic_null(-1, __func__, ERR_NOOBJ));
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

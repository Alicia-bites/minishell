/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:16:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:27:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lst_func_lst(t_ulist **list, void (*f)(void *))
{
	t_ulist	*obj;

	if (!list)
	{
		ft_panic(-1, ERR_NOOBJ);
		return ;
	}
	obj = *list;
	while (obj)
	{
		if (f)
			(f)(obj->content);
		obj = obj->next;
	}
}

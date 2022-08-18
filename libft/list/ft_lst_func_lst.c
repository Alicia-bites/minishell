/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:16:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lst_func_lst(t_ulist **list, void (*f)(void *))
{
	t_ulist	*obj;

	if (!list)
	{
		ft_panic(-1, __func__, ERR_NOOBJ);
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

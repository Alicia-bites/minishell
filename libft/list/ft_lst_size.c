/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:51:25 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:28:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_lst_size(t_ulist **lst)
{
	t_ulist	*obj;
	size_t	res;

	res = 0;
	if (!lst || !*lst)
		return (res);
	obj = *lst;
	while (obj)
	{
		obj = obj->next;
		res++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:57:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:27:58 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_last(t_ulist *lst)
{
	t_ulist	*obj;

	if (!lst)
		return (NULL);
	obj = lst;
	while (obj->next)
		obj = obj->next;
	return (obj);
}

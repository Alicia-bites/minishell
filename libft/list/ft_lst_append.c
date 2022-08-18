/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:07:14 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_append(t_ulist **lst, void *content)
{
	t_ulist	*last;
	t_ulist	*new;

	if (!lst)
		return (ft_panic_null(-1, __func__, ERR_NOOBJ));
	last = ft_lst_last(*lst);
	new = ft_lst_new(content);
	if (!new)
		return (NULL);
	if (last)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
	return (new);
}

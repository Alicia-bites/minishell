/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:15:43 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/09 11:40:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_clear(t_list *newcontent, t_list **newhead, void (*del)(void *))
{
	del(newcontent);
	ft_lstclear(newhead, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newprev;
	void	*newcontent;
	t_list	*newelt;

	newhead = NULL;
	newprev = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		newcontent = f(lst->content);
		newelt = ft_lstnew(newcontent);
		if (!newelt || !newcontent)
			return (ft_clear(newcontent, &newhead, del));
		if (!newhead)
			newhead = newelt;
		else
			newprev->next = newelt;
		newprev = newelt;
		lst = lst->next;
	}
	return (newhead);
}

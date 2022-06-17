/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:21:35 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/07 09:28:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iterator;
	t_list	*prev;
	int		i;

	iterator = lst;
	prev = NULL;
	i = 0;
	while (iterator)
	{
		prev = iterator;
		iterator = iterator->next;
		i++;
	}
	return (prev);
}

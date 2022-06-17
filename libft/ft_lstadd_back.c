/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:53:03 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/06 18:59:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*iterator;

	iterator = *alst;
	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{	
			while (iterator->next)
				iterator = iterator->next;
			iterator->next = new;
		}
	}
}

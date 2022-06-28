/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:47:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:28:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_new(void *content)
{
	t_ulist	*new;

	new = (t_ulist *)malloc(sizeof(t_ulist));
	if (!new)
	{
		ft_panic(-1, ERR_MALLOC);
		return (NULL);
	}
	if (!content)
		new->content = NULL;
	else
		new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

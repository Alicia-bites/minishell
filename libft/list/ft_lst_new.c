/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:47:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 13:37:02 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_new(void *content)
{
	t_ulist	*new;

	new = (t_ulist *)malloc(sizeof(t_ulist));
	if (!new)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	if (!content)
		new->content = NULL;
	else
		new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

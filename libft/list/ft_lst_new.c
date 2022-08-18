/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:47:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	*ft_lst_new(void *content)
{
	t_ulist	*new;

	new = (t_ulist *)malloc(sizeof(t_ulist));
	if (!new)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	if (!content)
		new->content = NULL;
	else
		new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

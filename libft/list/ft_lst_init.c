/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:48:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:27:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	**ft_lst_init(void)
{
	t_ulist	**list;

	list = (t_ulist **)malloc(sizeof(t_ulist *));
	if (!list)
	{
		ft_panic(-1, ERR_MALLOC);
		return (NULL);
	}
	*list = NULL;
	return (list);
}

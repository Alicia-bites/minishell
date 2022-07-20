/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:48:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 13:37:15 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	**ft_lst_init(void)
{
	t_ulist	**list;

	list = (t_ulist **)malloc(sizeof(t_ulist *));
	if (!list)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	*list = NULL;
	return (list);
}

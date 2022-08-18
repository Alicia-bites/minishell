/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:48:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ulist	**ft_lst_init(void)
{
	t_ulist	**list;

	list = (t_ulist **)malloc(sizeof(t_ulist *));
	if (!list)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	*list = NULL;
	return (list);
}

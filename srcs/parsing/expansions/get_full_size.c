/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 17:30:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_full_size(t_expanded *expanded_list)
{
	t_expanded	*it;
	int			length;

	it = expanded_list;
	length = 0;
	while (it)
	{
		length += ft_strlen(it->expanded);
		it = it->next;
	}
	return (length);
}

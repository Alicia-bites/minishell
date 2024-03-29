/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dollar_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:49:23 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 18:53:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_dollar_lst(t_expanded *lst)
{
	t_expanded	*iterator;

	iterator = lst;
	while (iterator)
	{
		printf("index = %d\n", iterator->index);
		printf("expanded = %s\n", iterator->expanded);
		printf("-----------------------------------------");
		iterator = iterator->next;
	}
}

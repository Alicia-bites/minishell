/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:11:16 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 18:53:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FOR DEBUG
// Print a linked list
void	print_lst(t_list *lst)
{
	t_list	*iterator;

	iterator = lst;
	while (iterator)
	{
		printf("index = %d\n", iterator->index);
		printf("token = %s\n", iterator->token);
		printf("toktype = %u\n", iterator->toktype);
		printf("-----------------------------------------");
		iterator = iterator->next;
	}
	printf("\n");
}

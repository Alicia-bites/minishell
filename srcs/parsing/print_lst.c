/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:11:16 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/28 15:43:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// FOR DEBUG
// Print a linked list
void	print_lst(t_list *lst)
{
	t_list	*iterator;
	int		i;

	iterator = lst;
	while (iterator)
	{
		printf("index = %d\n", iterator->index);
		if (ft_isspace(iterator->token[0]))
		{
			i = 0;
			while (iterator->token[i])
				printf("%d ", iterator->token[i++]);
			printf("\n");
		}
		else
			printf("token = %s\n", iterator->token);
		printf("toktype = %u\n", iterator->toktype);
		// printf("prev = %p\n", iterator->prev);
		// printf("next = %p\n", iterator->next);
		puts("-----------------------------------------");
		iterator = iterator->next;		
	}
	puts("\n");
}

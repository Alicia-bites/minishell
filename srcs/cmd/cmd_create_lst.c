/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:45:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/11 18:40:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_create_lst(t_list *tok, t_ulist **env_lst, t_ulist **cmd_lst)
{
	t_list	*obj;
	int	j;

	obj = tok;
	while (obj)
	{
		printf("ANTHOOOOOOOOOOO\n");
		printf("index = %d\n", obj->index);
		if (ft_isspace(obj->token[0]))
		{
			j = 0;
			while (obj->token[j])
				printf("%d ", obj->token[j++]);
			printf("\n");
		}
		else
			printf("token = %s\n", obj->token);
		printf("toktype = %u\n", obj->toktype);
		// printf("prev = %p\n", obj->prev);
		// printf("next = %p\n", obj->next);
		puts("-----------------------------------------");
		obj = obj->next;
	}
	return (0);
}

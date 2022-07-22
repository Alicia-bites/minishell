/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:24:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 17:21:05 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_list *tok)
{
	int		i;
	t_list	*obj;

	if (!tok)
		return ;
	obj = tok;
	i = 0;
	printf("index = %d\n", obj->index);
	if (ft_isspace(obj->token[0]))
	{
		while (obj->token[i])
			printf("%d ", obj->token[i++]);
		printf("\n");
	}
	else
		printf("token = %s\n", obj->token);
	printf("toktype = %u\n", obj->toktype);
	printf("prev = %p\n", obj->prev);
	printf("next = %p\n", obj->next);
	printf("%s\n", SEP_S);
}

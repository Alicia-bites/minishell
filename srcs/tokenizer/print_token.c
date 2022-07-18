/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:24:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 10:29:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_list *tok)
{
	t_list	*obj;
	int	i;

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

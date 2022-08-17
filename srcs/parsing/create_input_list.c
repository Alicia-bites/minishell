/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:43:07 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 12:15:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_input_list(t_chartype **input_list, char *str)
{
	int			length;
	int			i;

	// printf("str = %s\n", str);
	length = ft_strlen(str);
	(*input_list) = malloc(sizeof(t_chartype) * (length + 1));
	if (!(*input_list))
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return ;
	}
	ft_bzero((*input_list), sizeof(t_chartype) * (length + 1));
	i = 0;
	while (i < length)
	{
		(*input_list)[i].character = str[i];
		(*input_list)[i].length = length;
		i++;
	}
}

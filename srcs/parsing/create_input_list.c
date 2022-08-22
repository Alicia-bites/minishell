/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:43:07 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 19:30:46 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	quote_was_exp(int pos, int *tab)
{
	int	j;

	j = 0;
	if (!tab)
		return (0);
	if (tab[j])
	{
		while (tab[j])
		{
			if (pos == tab[j])
				return (1);
			j++;
		}
	}
	return (0);
}

void	create_input_list(t_chartype **input_list, char *str, int **tab_quote)
{
	int			length;
	int			i;

	length = ft_strlen(str);
	(*input_list) = malloc(sizeof(t_chartype) * (length + 1));
	if (!(*input_list))
	{
		ft_panic(MALLOC_FAILURE, __func__, NULL);
		return ;
	}
	ft_bzero((*input_list), sizeof(t_chartype) * (length + 1));
	i = 0;
	while (i < length)
	{
		(*input_list)[i].character = str[i];
		if (quote_was_exp(i, *tab_quote))
			(*input_list)[i].type = CH_WORD;
		(*input_list)[i].length = length;
		i++;
	}
	if (*tab_quote)
		free(*tab_quote);
}

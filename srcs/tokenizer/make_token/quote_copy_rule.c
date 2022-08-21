/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_copy_rule.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:58:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/21 11:20:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_quote_exp(t_chartype *input_list, int start, int end)
{
	int	n;

	n = 0;
	while (start <= end)
	{
		if (input_list[start].type == CH_WORD
			&& ((input_list[start].character == '\'')
				|| (input_list[start].character == '\"')))
			n++;
		start++;
	}
	return (n);
}

int	*check_quote_exp(t_chartype *input_list, int start, int end, int *n)
{
	int	*tab;
	int	i;
	int	k;

	tab = NULL;
	*n = count_quote_exp(input_list, start, end);
	if (*n > 0)
		tab = malloc(sizeof(int) * (*n));
	set_minus_one_tab(tab, (*n));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (start <= end)
	{
		if (input_list[start].type == CH_WORD
			&& ((input_list[start].character == '\'')
				|| (input_list[start].character == '\"')))
			tab[k++] = i;
		i++;
		start++;
	}
	return (tab);
}

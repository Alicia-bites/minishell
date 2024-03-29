/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op_in_expanded_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:11:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 16:58:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quote_in_expanded_list(t_expanded *expanded_list)
{
	int	n;

	n = 0;
	while (expanded_list)
	{
		if (found_quote(expanded_list->expanded))
			n += count_quote(expanded_list->expanded);
		expanded_list = expanded_list->next;
	}
	return (n);
}

int	count_op_in_expanded_list(t_expanded *expanded_list)
{
	int	n;

	n = 0;
	while (expanded_list)
	{
		if (found_operator(expanded_list->expanded))
			n += count_op(expanded_list->expanded);
		expanded_list = expanded_list->next;
	}
	return (n);
}

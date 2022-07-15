/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:52 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/30 15:55:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_squotes(t_chartype *input_list, int *start, int *end)
{
	int	quotes;
	int	i;

	quotes = 0;
	i = *start;
	while (i < *end)
	{
		if (input_list[i].character == '\'')
		{
			quotes++;
		}
		i++;
	}
	if (quotes > 0 && quotes % 2 == 0)
	{
		(*start) += 1;
		(*end)   -= 1;
	}
}

void	remove_dquotes(t_chartype *input_list, int *start, int *end)
{
	int	quotes;
	// int	tricky_case;
	int	i;

	// tricky_case = 0;
	quotes = 0;
	i = *start;
	while (i < *end)
	{
		// if (i > 0 && input_list[i].character == '\"'
		// 	&& input_list[i + 1].character == '\"')
		// {
		// 	quotes++;
		// 	tricky_case = 1;
		// }
		if (input_list[i].character == '\"')
		{
			quotes++;
		}
		i++;
	}
	if (quotes > 0 && quotes % 2 == 0)
	{
		(*start) += 1;
		(*end)   -= 1;
		// if (!tricky_case)
			// (*end) -= 1;
	}
}

void	remove_quotes(t_chartype *input_list, int *start, int *end)
{
	remove_squotes(input_list, start, end);
	remove_dquotes(input_list, start, end);
}
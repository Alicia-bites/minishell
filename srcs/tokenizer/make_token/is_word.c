/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/26 12:25:03 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	echo_n(t_chartype *input_list, int *end, int *seen_quote)
{
	int	tmp;

	tmp = *end;
	if (input_list[*end].character == 'e'
		&& input_list[*end + 1].character == 'c'
		&& input_list[*end + 2].character == 'h'
		&& input_list[*end + 3].character == 'o')
	{
		(*end) += 4;
		if (input_list[*end].type!= CH_SPACE)
			return (0);
		while (input_list[*end].type == CH_SPACE)
			(*end)++;
		while (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE)
		{
			*seen_quote = 1;
			(*end)++;
		}
		if (input_list[*end].character == '-')
			(*end)++;
		while (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE)
				(*end)++;
		if (input_list[*end].character == 'n')
			return (1);
	}
	*end = tmp;
	return (0);
}

static void	echo_special_treatment_second(t_chartype *input_list, int *end)
{
	while (input_list[*end].type == CH_D_QUOTE
		|| input_list[*end].type == CH_S_QUOTE)
		(*end)++;
	if (*end < input_list->length && input_list[*end].character != '-'
		&& input_list[*end + 1].character != 'n'
		&& (input_list[*end].character != '"'
			|| input_list[*end].type != CH_SPACE))
	{
		while (input_list[*end].type != CH_SPACE)
			(*end)--;
		return ;
	}
}

int	check_inside_quotes(t_chartype *input_list, int end)
{
	end++;
	if (input_list[end].character == '-'
		&& input_list[end + 1].character == 'n')
	{
		while (input_list[end + 1].character == 'n')
			end++;
		if (input_list[end].type == CH_D_QUOTE
			|| input_list[end].type == CH_S_QUOTE)
				return (1);
		else
			return (0);
	}
	return (0);
}

//parse input_list and move *end to the right posistion 
static void	echo_special_treatment(t_chartype *input_list,
	int *end, int *space, int seen_quote)
{
	int	tmp;

	tmp = *end;
	(*end) -= 1;
	while (input_list[*end].character == '-'
		&& input_list[*end + 1].character == 'n')
	{
		(*end)++;
		while (input_list[*end].character == 'n')
			(*end)++;
		if (!check_inside_quotes(input_list, *end) && seen_quote)
		{		
			(*end) = tmp;
			break ;
		}
		if (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE)
		while (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE)
			(*end)++;
		if (input_list[*end].character == '-'
			&& input_list[*end + 1].character == 'n')
		{
			while (input_list[*end + 1].character == 'n')
				(*end)++;	
			if (input_list[*end].type == CH_D_QUOTE
				|| input_list[*end].type == CH_S_QUOTE
				|| (input_list[*end].character == '-'
				&& input_list[*end + 1].character == 'n'))
					*space = 0;
		}
		while (input_list[*end].type == CH_SPACE)
		{
			if (!(*space))
				break ;
			(*end)++;
		}
		echo_special_treatment_second(input_list, end);
	}
	if (input_list[*end].character == '-'
		|| input_list[*end + 1].character == 'n')
		*end = tmp + 1;
}

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int	space;
	int	seen_quote;

	space = 1;
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (echo_n(input_list, end, &seen_quote))
			{
				echo_special_treatment(input_list, end, &space, seen_quote);
				built_echo(token_list, space);
				if (!space)
				{
					*start = *start + 5;
					*end = *start;
				}
				else
					*start = *end;
				return ;
			}
			(*end)++;
		}
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

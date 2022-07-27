/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 18:52:16 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// If between quotes,
// if space is found after n (no matter how many),
// return 0 --> not a valid '-n'
// If not between quotes, just return 1.
int	no_space_inside_quotes(t_chartype *input_list, int end, int quote)
{
	// printf("quote = %d\n", quote);
	if (quote)
	{
		if (input_list[end].type == CH_D_QUOTE
			|| input_list[end].type == CH_S_QUOTE)
				return (1);
		else
			return (0);
	}
	return (1);
}

// Check if after closing the last closing quote, you have a space. If so,
// you have a valid 'echo -n' combination. If something else than a space is
// found, return 0.
int	space_after_quote(t_chartype *input_list, int end, int quote)
{
	int	count_quote;

	count_quote = 0;
	while (end < input_list->length
		&& count_quote <= quote
		&& (input_list[end].type == CH_S_QUOTE
		|| input_list[end].type == CH_D_QUOTE))
		{
			end++;
			count_quote++;
		}
	if (input_list[end].type == CH_SPACE)
			return (1);
	else
		return (0);
}

// This function will check if we have a valid combination for "echo -n."
// If combo 'echo' is found, move *end forward 4.
// Then, if no space is following, return 0. If space, move forward as long
// as you find spaces.
// Then, move forward as long as you have quotes. Count them and put the 
// result in *quote.
// Then, if you find a '-', move forward 1. If not, stay where you are.
// Then, move forward as long as you have quotes.
// Then, if you where you are you have a 'n', it means you reached a winning
// combination. Return 1. Else, place *end back where your started and return 0.
static int	echo_n(t_chartype *input_list, int *end, int *quote)
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
			*quote++;
			(*end)++;
		}
		if (input_list[*end].character == '-')
			(*end)++;
		while (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE)
				(*end)++;
		if (input_list[*end].character == 'n'
			&& (no_space_inside_quotes(input_list, *end + 1, *quote)
			&& space_after_quote(input_list, *end + 1, *quote)))
			return (1);
	}
	*end = tmp;
	return (0);
}

static void	echo_special_treatment_second(t_chartype *input_list, int *end,
	int *quote)
{
	int	count_quote;

	count_quote = 0;
	while (input_list[*end].type == CH_D_QUOTE
		|| input_list[*end].type == CH_S_QUOTE)
	{
		(*end)++;
		count_quote++;
		if (count_quote == *quote)
		{
			*quote = 0;
			count_quote = 0;
		}
	}
	*quote = count_quote;
	if (*end + 1 < input_list->length && input_list[*end].character != '-'
		&& input_list[*end + 1].character != 'n'
		&& (input_list[*end].character != '"'
			|| input_list[*end].type != CH_SPACE))
	{
		while (input_list[*end].type != CH_SPACE)
			(*end)--;
		return ;
	}
}

//parse input_list and move *end to the right posistion 
static void	echo_special_treatment(t_chartype *input_list,
	int *end, int *space, int *quote)
{
	int	tmp;
	int	count_quote;

	count_quote = 0;
	tmp = *end;
	(*end) -= 1;
	while (input_list[*end].character == '-'
		&& input_list[*end + 1].character == 'n')
	{
		(*end)++;
		while (input_list[*end].character == 'n')
			(*end)++;
		if (!no_space_inside_quotes(input_list, *end, *quote))
		{		
			(*end) = tmp + 2;
			break ;
		}
		while (input_list[*end].type == CH_D_QUOTE
			|| input_list[*end].type == CH_S_QUOTE)
		{
			(*end)++;
			count_quote++;
			// printf("count_quote = %d\n", count_quote);
			if (count_quote == *quote)
			{
				*quote = 0;
				count_quote = 0;
			}
		}
		*quote = count_quote;
		// printf("quote = %d\n", *quote);
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
		echo_special_treatment_second(input_list, end, quote);
	}
	if (input_list[*end].character == '-'
		|| input_list[*end + 1].character == 'n')
		*end = tmp + 1;
}

int	empty_string(t_chartype *input_list, int end)
{
	if (end + 1 < input_list->length
		&& ((input_list[end].type == CH_S_QUOTE
		&& input_list[end + 1].type == CH_S_QUOTE)
		|| (input_list[end].type == CH_D_QUOTE
		&& input_list[end + 1].type == CH_D_QUOTE)))
			return (1);
	return (0);
}

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int	space;
	int	quote;

	space = 1;
	quote = 0;
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (echo_n(input_list, end, &quote))
			{
				echo_special_treatment(input_list, end, &space, &quote);
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
		if (!empty_string(input_list, *end))
			is_quote(input_list, start, end, token_list);			
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:08:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 19:19:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
int	echo_n(t_chartype *input_list, int *end, int *quote)
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
			(*quote)++;
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
void	echo_special_treatment(t_chartype *input_list,
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

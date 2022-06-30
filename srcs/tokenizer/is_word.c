/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/30 16:14:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	echo_n(t_chartype *input_list, int *end)
{
	int	tmp;

	tmp = *end;
	if (input_list[*end].character == 'e'
		&& input_list[*end + 1].character == 'c'
		&& input_list[*end + 2].character == 'h'
		&& input_list[*end + 3].character == 'o')
		{
			(*end) += 4;
			while (input_list[*end].type == CH_SPACE)
			{
				(*end)++;
			}
			while (input_list[*end].type == CH_D_QUOTE
				|| input_list[*end].type == CH_S_QUOTE)
				{
					(*end)++;
				}
			if (input_list[*end].character == '-')
				(*end)++;
			while (input_list[*end].type == CH_D_QUOTE
				|| input_list[*end].type == CH_S_QUOTE)
				{
					(*end)++;
				}
			if (input_list[*end].character == 'n')
				return (1);
		}
	*end = tmp;
	return (0);
}

static void	echo_special_treatment(t_chartype *input_list, int *start,
	int *end, int *space)
{
	(*end) -= 1;
	while (input_list[*end].character == '-'
		&& input_list[*end + 1].character == 'n')
		{
			(*end)++;
			while (input_list[*end].character == 'n')
				(*end)++;
			while (input_list[*end].type == CH_D_QUOTE
				|| input_list[*end].type == CH_S_QUOTE)
			{
				(*end)++;
			}
			if (input_list[*end].character == '-')
			{
				*space = 0;
			}
			while (input_list[*end].type == CH_SPACE)
			{
				if (!(*space))
					break ;					
				(*end)++;
			}
			while (input_list[*end].type == CH_D_QUOTE
				|| input_list[*end].type == CH_S_QUOTE)
			{
				(*end)++;
			}
			if (input_list[*end].character != '-'
				&& input_list[*end + 1].character != 'n'
				&& (input_list[*end].character != '"'
				|| input_list[*end].type != CH_SPACE))
				{
					while (input_list[*end].type != CH_SPACE)
						(*end)--;
					return ;					
				}
		}
}

static void	built_echo(t_list **token_list, int space)
{
	char *token;
	
	if (!space)
		token = "echo";
	else
		token = "echo -n";
	add_token_to_list(token, token_list);
}

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int space;

	space = 1;
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (echo_n(input_list, end))
			{
				echo_special_treatment(input_list, start, end, &space);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/30 11:14:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	echo_n(t_chartype *input_list, int end, int *spaces)
{
	if (input_list[end].character == 'e'
		&& input_list[end + 1].character == 'c'
		&& input_list[end + 2].character == 'h'
		&& input_list[end + 3].character == 'o')
		{
			end += 4;
			while (input_list[end].type == CH_SPACE)
			{
				end++;
				(*spaces)++;				
			}
			if (input_list[end].character == '-' 
				&& input_list[end + 1].character == 'n')
				return (1);
		}
	return (0);
}

static void	echo_special_treatment(t_chartype *input_list, int *start,
	int *end, int spaces)
{
	(*end) += 5;
	(*end) += (spaces - 1);
	while (input_list[*end].character == '-'
		&& input_list[*end + 1].character == 'n')
		{
			(*end)++;
			while (input_list[*end].character == 'n')
				(*end)++;
			while (input_list[*end].type == CH_SPACE)
				(*end)++;
		}
}

void	handle_echo(t_list **token_list)
{
	char *token;
	
	token = "echo -n";
	add_token_to_list(token, token_list);
}

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int	spaces;
	
	spaces = 0;
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (echo_n(input_list, *end, &spaces))
			{
				echo_special_treatment(input_list, start, end, spaces);
				(*end)--;
			}
			if (spaces)
			{
				// printf(" input_list[*end].character = %c\n", input_list[*end].character);
				handle_echo(token_list);
				*start = (*end);
				return ;
			}
			(*end)++;
		}
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/29 17:31:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo_n(t_chartype *input_list, int end)
{
	if (input_list[end].character == 'e'
		&& input_list[end + 1].character == 'c'
		&& input_list[end + 2].character == 'h'
		&& input_list[end + 3].character == 'o'
		&& input_list[end + 4].type == CH_SPACE
		&& input_list[end + 5].character == '-'
		&& input_list[end + 6].character == 'n')
			return (1);
	return (0);
}

void	echo_special_treatment(t_chartype *input_list, int *start, int *end)
{
	(*end) += 5;
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

void	is_word(t_chartype *input_list, int *start, int *end,
	t_list **token_list)
{	
	int	echo;
	
	echo = 0;
	if (input_list[*end].type == CH_WORD)
	{
		while (input_list[*end].type == CH_WORD)
		{
			if (echo_n(input_list, *end))
			{
				echo_special_treatment(input_list, start, end);
				echo = 1;				
			}
			if (echo == 1)
				break ;
			(*end)++;
		}
		// printf("end = %d\n", *end);
		built_token(input_list, *start, *end, token_list);
		*start = *end;
	}
}
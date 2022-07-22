/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:59:00 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 14:37:20 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	echo_special_treatment_second()
{
	while (input_list[*end].type == CH_D_QUOTE
		|| input_list[*end].type == CH_S_QUOTE)
		(*end)++;
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

static void	echo_special_treatment(t_chartype *input_list,
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
			(*end)++;
		if (input_list[*end].character == '-')
			*space = 0;
		while (input_list[*end].type == CH_SPACE)
		{
			if (!(*space))
				break ;					
			(*end)++;
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
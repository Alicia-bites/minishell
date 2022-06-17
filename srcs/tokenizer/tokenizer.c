/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/17 14:44:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_char_word(char c)
{
	if (ft_isalnum(c) || c == ';' || c == ',' || c == ':' || c == '.'
		|| c == '?' || c == '_' || c == '-')
			return (1);
	return (0);
}

int	tokenize(t_chartype *input_list)
{
	int	i;

	i = 0;
	while (input_list[i].character)
	{
		if (is_char_word(input_list[i].character))
		{
			input_list[i].type = CH_WORD;
			printf("%c -> %d\n", input_list[i].character, input_list[i].type);
		}
		i++;
	}
	return (i);
}
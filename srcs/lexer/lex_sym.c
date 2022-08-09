/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_sym.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:08:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/09 09:55:36 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	is_special_character(char c)
{
	int	i;
//	char special_char[7] = "`!#&;,/"; // ORIGIN
	char special_char[7] = "`!#&;,"; // ANTHO: remove / otherwise not possible to define a regular path /user/Desktop

	i = 0;
	while (i <= 7)
	{
		if (c == special_char[i])
			return (1);
		i++;
	}
	return (0);
}

int	lex_sym(char *str, int *err)
{
	int i;

	i = 0;
	is_special_character('a');
	while (str[i])
	{
		if (is_special_character(str[i]) && !between_quotes(str, i))
		{
			*err = SPECIAL_CHAR;
			printf("smbash: syntax error. Please put special characters between quotes.\n");
			return (*err);
		}
		i++;
	}
	return (0);
}

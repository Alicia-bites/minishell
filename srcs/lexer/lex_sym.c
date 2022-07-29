/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_sym.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:08:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 16:50:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between_quotes(char *str, int pos)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	s = 0;
	d = 0;
	while (str[i] && i < pos)
	{
		if (str[i] == '\'' && !(d % 2))
			s++;
		if (str[i] == '\"' && !(s % 2))
			d++;
		i++;
	}
	if ((s % 2) || (d % 2))
		return (1);
	return (0);
}

int	is_special_character(char c)
{
	int	i;
	char special_char[7] = "`!#&;,/";

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
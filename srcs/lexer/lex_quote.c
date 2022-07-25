/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 19:55:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	inside_doubles(char *str)
{
	int	i;
	int	sg;

	i = 0;
	sg = 0;
	while (str[i])
	{
		if (str[i] == '"' && ft_strlen(str) > 2)
		{
			i++;
			while (str[i] && str[i] != '"')
			{
				if (str[i] == '\'')
					sg++;
				i++;
			}
		}
		i++;
	}
	return (sg);
}

int	inside_singles(char *str)
{
	int	i;
	int	db;

	i = 0;
	db = 0;
	while (str[i])
	{
		if (str[i] == '\'' && ft_strlen(str) > 2)
		{
			i++;
			while (str[i] && str[i] != '\'')
			{
				if (str[i] == '"')
					db++;
				i++;
			}
		}
		i++;
	}
	return (db);
}

int	count_single_for_lexer(char *str)
{
	int	i;
	int	c_single;

	i = 0;
	c_single = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			c_single++;
		i++;
	}
	c_single -= inside_doubles(str);
	return (c_single);
}

int	count_double_for_lexer(char *str)
{
	int	i;
	int	c_double;

	i = 0;
	c_double = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			c_double++;
		i++;
	}
	c_double -= inside_singles(str);
	return (c_double);
}

int	lex_quote(char *str, int *err)
{
	int	c_double;
	int	c_single;

	c_double = count_double_for_lexer(str);
	c_single = count_single_for_lexer(str);
	if (c_double % 2 != 0 || c_single % 2 != 0)
	{
		*err = MISSING_QUOTES;
		printf("smbash: syntax error. Please check quotes.\n");
	}
	return (*err);
}

// int	lex_quote(char *str, int *err)
// {
// 	if (count_single(str) % 2 || count_double(str) % 2)
// 	{
// 		if (count_single(str) % 2 && !(count_double(str) % 2))
// 			if (double_inside(str))
// 				return (0);
// 		if (!(count_single(str) % 2) && count_double(str) % 2)
// 			if (single_inside(str))
// 				return (0);
// 		*err = MISSING_QUOTES;
// 		printf("smbash: syntax error. Please check quotes.\n");
// 	}
// 	return (*err);
// }

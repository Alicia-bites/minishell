/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 14:11:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	inside_doubles(char *str)
// {
// 	int	i;
// 	int	db;
// 	int	opening_quote;

// 	i = 0;
// 	db = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\"' && ft_strlen(str) > 2)
// 		{
// 			opening_quote = i;
// 			i++;
// 			if (str[i] == '\"' && (i + 1) < ft_strlen(str)
// 				&& i == opening_quote + 1)
// 					i++;
// 			while (str[i] && str[i] != '\"')
// 				i++;
// 			while (str[i] && i > opening_quote)
// 			{
// 				if (str[i] == '\'')
// 					db++;
// 				i--;
// 			}
// 		}
// 		i++;
// 	}
// 	return (db);
// }

// int	inside_singles(char *str)
// {
// 	int	i;
// 	int	db;
// 	int	opening_quote;

// 	i = 0;
// 	db = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'' && ft_strlen(str) > 2)
// 		{
// 			opening_quote = i;
// 			i++;
// 			if (str[i] == '\'' && (i + 1) < ft_strlen(str)
// 				&& i == opening_quote + 1)
// 					i++;
// 			while (str[i] && str[i] != '\'')
// 				i++;
// 			while (str[i] && i > opening_quote)
// 			{
// 				if (str[i] == '\"')
// 					db++;
// 				i--;
// 			}
// 		}
// 		i++;
// 	}
// 	// printf("db = %d\n", db);
// 	return (db);
// }

// int	count_single_for_lexer(char *str)
// {
// 	int	i;
// 	int	c_single;

// 	i = 0;
// 	c_single = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'')
// 			c_single++;
// 		i++;
// 	}
// // 	printf("c_single before = %d\n", c_single);
// 	// printf("inside double = %d\n", inside_doubles(str));
// 	c_single -= inside_doubles(str);
// 	// printf("c_single = %d\n", c_single);
// 	return (c_single);
// }

// int	count_double_for_lexer(char *str)
// {
// 	int	i;
// 	int	c_double;

// 	i = 0;
// 	c_double = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\"')
// 			c_double++;
// 		i++;
// 	}
// 	// printf("c_double before = %d\n", c_double);
// 	// printf("inside singles = %d\n", inside_singles(str));
// 	c_double -= inside_singles(str);
// 	// printf("c_double = %d\n", c_double);
// 	return (c_double);
// }

void	count_quotes_lexer(int *s, int *d, char *str)
{
	int	i;

	i = 0;
	// printf("str = %s\n", str);
	while (str[i])
	{
		if (str[i] == '\'' && !(*d % 2))
			(*s)++;
		if (str[i] == '\"' && !(*s % 2))
			(*d)++;
		i++;
	}
	// printf("s = %d\n", *s);
	// printf("d = %d\n", *d);
}

int	lex_quote(char *str, int *err)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	// printf("s = %d\n", s);
	// printf("d = %d\n", d);
	count_quotes_lexer(&s, &d, str);
	if (d % 2 != 0 || s % 2 != 0)
	{
		*err = MISSING_QUOTES;
		printf("smbash: syntax error. Please check quotes.\n");
	}
	return (*err);
}

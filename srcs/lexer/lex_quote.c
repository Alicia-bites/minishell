/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 15:59:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	double_inside(char *str)
{
	int	i;
	int	sg;

	i = 0;
	sg = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
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

int	single_inside(char *str)
{
	int	i;
	int	db;

	i = 0;
	db = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
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

int	lex_quote(char *str, int *err)
{

	
	if (count_single(str) % 2 || count_double(str) % 2)
	{
		if (count_single(str) % 2 && !(count_double(str) % 2))
			if (double_inside(str))
				return (*err);
		if (!(count_single(str) % 2) && count_double(str) % 2)
			if (single_inside(str))
				return (*err);
		*err = MISSING_QUOTES;
		printf("smbash: syntax error. Please check quotes.\n");		
	}
	return (*err);
}

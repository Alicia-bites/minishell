/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_brackets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:05:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 14:56:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_if_r_bracket(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '}')
			return (1);
		if (str[i] == '{')
			break ;
		i++;
	}
	return (0);
}

static int	unclosed_quote_in_brackets(char *str, int pos)
{
	int	s;
	int	d;

	s = 0;
	d = 0;
	while (str[pos] && str[pos] != '}')
	{
		if (str[pos] == '\'')
			s++;
		if (str[pos] == '\"')
			d++;
		pos++;
	}
	if (d && d % 2)
		return (1);
	if (s && s % 2)
		return (1);
	return (0);
}

static int	quotes_in_brackets(char *str, int pos)
{
	int	s;
	int	d;

	s = 0;
	d = 0;
	while (str[pos] && str[pos] != '}')
	{
		if (str[pos] == '\'')
			s++;
		if (str[pos] == '\"')
			d++;
		pos++;
	}
	if (d && !(d % 2))
		return (1);
	if (s && !(s % 2))
		return (1);
	return (0);
}

static int	bad_substitution(int *err)
{
	*err = BAD_SUB;
	ft_putendl_fd(MSGERR_BRACKETS, 2);
	return (*err);
}

int	lex_brackets(char *str, int *err)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '{')
		{
			if (!check_if_r_bracket(str, (i + 2))
				|| unclosed_quote_in_brackets(str, i + 2))
			{
				*err = MISSING_BRACKET;
				ft_putendl_fd(MSGERR_BRACKETS, 2);
				return (*err);
			}
			if (quotes_in_brackets(str, i + 2))
				return (bad_substitution(err));
		}
		i++;
	}
	return (*err);
}

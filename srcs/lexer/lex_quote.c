/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 16:31:21 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_quotes_lexer(int *s, int *d, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !(*d % 2))
			(*s)++;
		if (str[i] == '\"' && !(*s % 2))
			(*d)++;
		i++;
	}
}

int	lex_quote(char *str, int *err)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	count_quotes_lexer(&s, &d, str);
	if (d % 2 != 0 || s % 2 != 0)
	{
		*err = MISSING_QUOTES;
		ft_putendl_fd(MSGERR_QUOTE, 2);
	}
	return (*err);
}

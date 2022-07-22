/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_brackets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:05:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 17:24:21 by amarchan         ###   ########.fr       */
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

int	lex_brackets(char *str, int *err)
{
	int	i;
	int	r_bracket;
	int	l_bracket;

	i = 0;
	r_bracket = 0;
	l_bracket = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '{')
		{
			if (!check_if_r_bracket(str, (i + 2)))
			{
				*err = MISSING_BRACKET;
				printf("smbash: syntax error. Please check brackets.\n");
				return (*err);
			}
		}
		i++;
	}
	return (*err);
}

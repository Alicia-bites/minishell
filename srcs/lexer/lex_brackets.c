/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_brackets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:05:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 16:47:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (str[i] == '{')
			l_bracket++;
		if (str[i] == '}')
			r_bracket++;
		i++;
	}
	if (l_bracket > r_bracket)
	{
		*err = MISSING_BRACKET;
		printf("smbash: syntax error. Please check brackets.\n");
		return (*err);
	}
	return (0);
}
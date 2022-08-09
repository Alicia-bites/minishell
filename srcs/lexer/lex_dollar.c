/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:45:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/31 14:10:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_bad_dollar_combo(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i + 1 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '$'
			|| (i + 3 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '{'
				&& str[i + 2] == '$' && str[i + 3] == '}'))
		{
			return (i);
		}
		i++;
	}
	return (0);
}
int	lex_dollar(char *str, int *err)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (found_bad_dollar_combo(str) && !between_quotes(str, found_bad_dollar_combo(str)))
		{
			*err = ERR_DOLLAR;
			printf("smbash: syntax error. Same old story, dollar following dollar.\n");
			return (*err);
		}
		i++;
	}
	return (0);
}
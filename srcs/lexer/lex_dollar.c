/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:45:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 15:58:05 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	found_bad_dollar_combo(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i + 1 < len && str[i] == '$' && str[i + 1] == '$')
			|| (i + 3 < len && str[i] == '$' && str[i + 1] == '{'
				&& str[i + 2] == '$' && str[i + 3] == '}'))
			return (i);
		i++;
	}
	return (0);
}

int	lex_dollar(char *str, int *err)
{
	int	len;

	len = ft_strlen(str);
	if (found_bad_dollar_combo(str, len)
		&& !between_quotes(str, found_bad_dollar_combo(str, len)))
	{
		*err = ERR_DOLLAR;
		ft_putendl_fd(MSGERR_DOLLAR, 2);
		return (*err);
	}
	return (0);
}

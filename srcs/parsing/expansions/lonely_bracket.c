/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_bracket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:56:59 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 18:57:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lonely_bracket(char *str)
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
	if (l_bracket < r_bracket)
		return (1);
	return (0);
}

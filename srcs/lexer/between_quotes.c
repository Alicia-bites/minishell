/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:41:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 17:42:02 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between_quotes(char *str, int pos)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	s = 0;
	d = 0;
	while (str[i] && i < pos)
	{
		if (str[i] == '\'' && !(d % 2))
			s++;
		if (str[i] == '\"' && !(s % 2))
			d++;
		i++;
	}
	if ((s % 2) || (d % 2))
		return (1);
	return (0);
}

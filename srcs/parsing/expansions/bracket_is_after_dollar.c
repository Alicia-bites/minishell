/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_is_after_dollar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:13:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/20 10:21:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bracket_is_after_dollar(char *str, int pos)
{
	while (str[pos])
	{
		if (str[pos] == '$')
		{
			if (str[pos + 1] == '{')
				return (1);
			else
				return (0);
		}
		pos--;
	}
	return (0);
}

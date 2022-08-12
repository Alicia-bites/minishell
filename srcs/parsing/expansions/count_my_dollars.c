/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_my_dollars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:03:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:33:16 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_dollars_in_str(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (i + 1 < ft_strlen(str) && str[i] == '$'
			&& !between_single_quotes(str, i))
			n++;
		i++;
	}
	return (n);
}

int	count_my_dollars(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (i + 1 < ft_strlen(str) && str[i] == '$'
			&& (str[i + 1] == '\'' || str[i + 1] == '"'))
			n++;
		i++;
	}
	return (n);
}

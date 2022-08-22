/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_slash_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:34:54 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 12:32:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_slash_in_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != '/')
			return (0);
		i++;
	}
	return (1);
}

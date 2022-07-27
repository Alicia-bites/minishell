/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seen_equal_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:48:08 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 17:48:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	seen_equal_last(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '=' && (i == ft_strlen(token) - 1))
			return (1);
		i++;
	}
	return (0);
}
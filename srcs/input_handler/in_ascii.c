/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:11:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 11:11:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_ascii(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] >= 127)
			return (0);
		i++;
	}
	return (1);
}

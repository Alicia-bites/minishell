/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:58:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/28 10:58:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chartype.h"
#include "ft_string.h"

int	ft_str_isdigit(char *str)
{
	long long	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_ispolarity(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

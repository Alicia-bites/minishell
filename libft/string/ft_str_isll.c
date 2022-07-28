/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:58:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/28 11:49:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chartype.h"
#include "ft_convert.h"
#include "ft_string.h"

static int	ft_str_isll_check_str(char *str, int sign)
{
	size_t		len_str;
	size_t		len_max;
	long long	i;

	len_str = ft_strlen(str);
	len_max = ft_strlen(STR_LONG_LONG_MAX);
	i = 0;
	if (len_str > len_max)
		return (0);
	else if (len_str == len_max)
	{
		while (str[i])
		{
			if (sign > 0 && str[i] > STR_LONG_LONG_MAX[i])
				return (0);
			if (sign < 0 && str[i] > STR_LONG_LONG_MIN[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_str_isll(char *str)
{
	long long	i;
	long long	j;
	int			sign;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_ispolarity(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	j = i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (ft_str_isll_check_str(&str[j], sign));
}

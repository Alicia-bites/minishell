/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:05:50 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/07 12:13:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*a;

	i = 0;
	a = (char *)big;
	n = ft_strlen(little);
	if (n == 0 || little == big)
		return (a);
	while (a[i] && i < len)
	{
		j = 0;
		while (a[i + j] && little[j] && a[i + j] == little[j] && i + j < len)
			j++;
		if (j == n)
			return ((char *)&a[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:29:09 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 14:16:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
	while (a[i])
	{
		j = 0;
		while (a[i + j] && little[j] && a[i + j] == little[j])
			j++;
		if (j == n)
			return ((char *)&a[i]);
		i++;
	}
	return (0);
}

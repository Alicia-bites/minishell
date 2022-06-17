/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:46:11 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/10 16:54:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dest = (char *)s1;
	src = (const char *)s2;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (s1);
}

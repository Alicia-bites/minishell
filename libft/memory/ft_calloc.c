/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:22:17 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/06 14:34:46 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	i;

	dest = malloc (nmemb * size);
	if (dest == NULL)
		return (dest);
	i = 0;
	while (i < nmemb * size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:18:13 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/10 16:55:36 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	j;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (dest_size < size)
	{
		j = 0;
		while (src[j] != '\0' && dest_size + j < size - 1)
		{
			dest[dest_size + j] = src[j];
			j++;
		}
		dest[dest_size + j] = '\0';
		return (dest_size + src_size);
	}
	else
		return (size + src_size);
}

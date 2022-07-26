/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/16 14:15:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;

	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (ucdest >= ucsrc)
	{
		while (n != '\0')
		{
			n--;
			ucdest[n] = ucsrc[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (ucdest);
}

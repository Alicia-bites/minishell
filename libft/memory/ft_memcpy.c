/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:24:33 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/16 14:15:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ucsrc;
	unsigned char	*ucdest;
	int				i;

	ucsrc = (unsigned char *)src;
	ucdest = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < (int) n)
	{
		ucdest[i] = ucsrc[i];
		i++;
	}
	return (ucdest);
}

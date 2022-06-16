/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:56:23 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/03 15:41:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr == 0)
		return (2);
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*dest;
	long int	nbr;
	int			len;

	nbr = n;
	len = ft_nlen(nbr);
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		dest[0] = '0';
	dest[--len] = '\0';
	while (nbr)
	{
		dest[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (dest);
}

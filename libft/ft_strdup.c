/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:17:05 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/06 14:58:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*copy;

	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	copy = malloc(sizeof(*copy) * (len + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

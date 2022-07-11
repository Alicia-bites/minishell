/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptrptr_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:16:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/04/11 11:35:46 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

char	*ft_free_ptrptr_str(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

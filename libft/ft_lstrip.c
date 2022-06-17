/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:48:27 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 11:37:28 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrip(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) > 11)
	{
		while (s[i] == '0')
			i++;
	}
	while (s[i] && ft_isspace(s[i]))
		i++;
	ft_memmove(s, s + i, ft_strlen(s) - i + 1);
}

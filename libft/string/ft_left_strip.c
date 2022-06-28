/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_strip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:48:27 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 14:53:25 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_left_strip(char *s)
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

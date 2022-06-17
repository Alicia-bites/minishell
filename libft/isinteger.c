/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinteger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:44:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 11:36:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//check if argument is integer
int	isinteger(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

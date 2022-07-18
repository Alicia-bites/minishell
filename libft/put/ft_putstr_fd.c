/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:37:28 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 11:35:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		return (res);
	while (s[i])
		res += ft_putchar_fd(s[i++], fd);
	return (res);
}

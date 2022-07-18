/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 11:32:45 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	res;

	res = 0;
	if (!s)
		return (res);
	res += ft_putstr_fd(s, fd);
	res += ft_putchar_fd('\n', fd);
	return (res);
}

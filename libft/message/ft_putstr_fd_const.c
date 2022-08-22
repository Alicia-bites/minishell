/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_const.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:15:02 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 18:38:14 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

int	ft_putstr_fd_const(const char *s, int fd)
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

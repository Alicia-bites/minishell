/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_const.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:12:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 13:19:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

int	ft_putendl_fd_const(const char *s, int fd)
{
	int	res;

	res = 0;
	if (!s)
		return (res);
	res += ft_putstr_fd_const(s, fd);
	res += ft_putchar_fd_const('\n', fd);
	return (res);
}

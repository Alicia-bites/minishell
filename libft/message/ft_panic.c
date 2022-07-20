/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 13:32:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

int	ft_panic(int errcode, char *filename, char *msg)
{
	int		res;
	char	*err_msg;

	res = 0;
	err_msg = NULL;
	(void)errcode;
	(void)msg;
	if (errcode >= 0)
		err_msg = strerror(errcode);
	else if (msg)
		err_msg = msg;
	else
		err_msg = NULL;
	res += ft_putendl_fd("Error:", 2);
	if (filename)
	{
		res += ft_putstr_fd("file: ", 2);
		res += ft_putendl_fd(filename, 2);
	}
	res += ft_putstr_fd("message: ", 2);
	res += ft_putendl_fd(err_msg, 2);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:40:39 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

void	ft_panic(int errcode, char *msg)
{
	char	*err_file;
	char	*err_msg;

	err_file = __FILE__;
	err_msg = NULL;
	(void)errcode;
	(void)msg;
	if (errcode >= 0)
		err_msg = strerror(errcode);
	else if (msg)
		err_msg = msg;
	else
		err_msg = NULL;
	ft_putstr_fd("Error:\nfile: ", 2);
	ft_putendl_fd(err_file, 2);
	ft_putstr_fd("message: ", 2);
	ft_putendl_fd(err_msg, 2);
}

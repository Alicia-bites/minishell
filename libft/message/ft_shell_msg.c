/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:05:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 10:12:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

int	ft_shell_msg(int errcode, char *data)
{
	int		res;
	char	*message;

	message = strerror(errcode);
	res = 0;
	res += ft_putstr_fd("Error: ", 2);
	res += ft_putstr_fd(message, 2);
	res += ft_putstr_fd(": ", 2);
	res += ft_putendl_fd(data, 2);
	if (res <= 0)
		res = 1;
	return (res);
}

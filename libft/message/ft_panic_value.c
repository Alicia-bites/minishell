/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/27 14:37:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

int	ft_panic_value(int errcode, char *filename, char *msg, int value)
{
	ft_panic(errcode, filename, msg);
	return (value);
}

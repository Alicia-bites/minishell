/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 13:33:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

void	*ft_panic_null(int errcode, char *filename, char *msg)
{
	ft_panic(errcode, filename, msg);
	return (NULL);
}

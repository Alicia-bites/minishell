/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:09:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

void	*ft_panic_null(int errcode, const char *filename, char *msg)
{
	ft_panic(errcode, filename, msg);
	return (NULL);
}

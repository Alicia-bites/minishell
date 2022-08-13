/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_init_check_binary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:53:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 11:05:21 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_init_check_binary(void)
{
	if (fd_access(HD_BIN_FALSE, ACCESS_X))
		return (EXIT_FAILURE);
	if (fd_access(HD_BIN_TRUE, ACCESS_X))
		return (EXIT_FAILURE);
	return (0);
}

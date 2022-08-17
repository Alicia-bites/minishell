/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_init_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:38:21 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 16:01:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_init_check(void)
{
	extern t_global	g_msl;

	if (hd_init_check_binary() || hd_init_check_tmp())
	{
		g_msl.exit = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	else
		return (0);
}

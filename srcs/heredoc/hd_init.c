/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:11:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 10:29:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_init(t_list *tok, t_cmd *cmd, long long *hd_exit)
{
	extern t_global	g_msl;

	if (!hd_create_name(tok, cmd))
	{
		g_msl.exit = EXIT_FAILURE;
		*hd_exit = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	if (hd_open(cmd))
	{
		g_msl.exit = EXIT_FAILURE;
		*hd_exit = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	return (0);
}

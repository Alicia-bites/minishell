/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:11:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 16:16:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	hd_init(t_list *tok, t_cmd *cmd)
{
	extern t_global	g_msl;
	char			*hd_name;
	int				hd;

	hd_name = NULL;
	hd = 0;
	if (hd_init_check())
		return (-1);
	hd_name = hd_create_name(tok);
	if (!hd_name)
	{
		g_msl.exit = EXIT_FAILURE;
		return (-1);
	}
	hd = hd_open(hd_name);
	if (hd < 0)
		return (-1);
	if (cmd)
		hd_tokfile_link_cmd(cmd, hd, hd_name);
	else
		free(hd_name);
	return (hd);
}

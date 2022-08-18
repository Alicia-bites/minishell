/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:11:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 14:52:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	hd_init(t_list *tok, t_cmd *cmd)
{
	extern long long	g_exit;
	char			*hd_name;
	int				hd;

	hd_name = NULL;
	hd = 0;
	if (hd_init_check())
		return (-1);
	hd_name = hd_create_name(tok);
	if (!hd_name)
	{
		g_exit = EXIT_FAILURE;
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

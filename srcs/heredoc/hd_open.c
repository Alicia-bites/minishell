/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:14:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 15:59:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_open(char *hd_name)
{
	extern t_global	g_msl;
	int				res;

	res = -1;
	res = open(hd_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (res < 0)
	{
		free(hd_name);
		g_msl.exit = EXIT_FAILURE;
	}
	return (res);
}

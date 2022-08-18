/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:14:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 14:52:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_open(char *hd_name)
{
	extern long long	g_exit;
	int				res;

	res = -1;
	res = open(hd_name, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (res < 0)
	{
		free(hd_name);
		g_exit = EXIT_FAILURE;
	}
	return (res);
}

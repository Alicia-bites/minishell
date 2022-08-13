/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_init_check_tmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:53:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 11:21:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_init_check_tmp(void)
{
	int	dir;

	dir = open(HD_TMP_DIR, O_DIRECTORY);
	if (dir < 0)
	{
		ft_shell_msg(ENOENT, HD_TMP_DIR);
		return (EXIT_FAILURE);
	}
	close(dir);
	if (access(HD_TMP_DIR, W_OK) != 0)
	{
		ft_shell_msg(EACCES, HD_TMP_DIR);
		return (EXIT_FAILURE);
	}
	return (0);
}

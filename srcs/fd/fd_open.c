/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:00:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 14:13:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_open(char *fd_name, int mode)
{
	int	res;

	res = -1;
	if (mode == O_RDONLY)
		res = open(fd_name, O_RDONLY);
	else if (mode == O_WRONLY)
		res = open(fd_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (mode == O_APPEND)
		res = open(fd_name, O_CREAT | O_APPEND | O_WRONLY, 0644);
	return (res);
}

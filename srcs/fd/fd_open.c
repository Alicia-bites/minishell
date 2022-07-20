/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:00:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 16:40:39 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_open(char *fd, int mode)
{
	int	res;

	res = -1;
	if (mode == O_RDONLY)
		res = open(fd, O_RDONLY);
	else if (mode == O_WRONLY)
		res = open(fd, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (mode == O_APPEND)
		res = open(fd, O_APPEND | O_TRUNC | O_CREAT, 0644);
	return (res);
}

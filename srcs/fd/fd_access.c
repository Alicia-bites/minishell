/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:17:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 14:47:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_access(char *fd, int mode)
{
	if (access(fd, F_OK) != 0)
	{
		ft_shell_msg(ENOENT, fd);
		return (8);
	}
	else if (mode == ACCESS_X && access(fd, X_OK) != 0)
	{
		ft_shell_msg(EACCES, fd);
		return (ACCESS_X);
	}
	else if (mode == ACCESS_W && access(fd, W_OK) != 0)
	{
		ft_shell_msg(EACCES, fd);
		return (ACCESS_W);
	}
	else if (mode == ACCESS_R && access(fd, R_OK) != 0)
	{
		ft_shell_msg(EACCES, fd);
		return (ACCESS_R);
	}
	return (0);
}

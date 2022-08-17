/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:17:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 14:15:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_access(char *fd_name, int mode)
{
	if (access(fd_name, F_OK) != 0)
	{
		ft_shell_msg(ENOENT, fd_name);
		return (8);
	}
	else if (mode == ACCESS_X && access(fd_name, X_OK) != 0)
	{
		ft_shell_msg(EACCES, fd_name);
		return (ACCESS_X);
	}
	else if (mode == ACCESS_W && access(fd_name, W_OK) != 0)
	{
		ft_shell_msg(EACCES, fd_name);
		return (ACCESS_W);
	}
	else if (mode == ACCESS_R && access(fd_name, R_OK) != 0)
	{
		ft_shell_msg(EACCES, fd_name);
		return (ACCESS_R);
	}
	return (0);
}

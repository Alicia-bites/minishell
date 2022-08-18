/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:34:19 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 17:48:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_error_msg(char *str, int i)
{
	ft_putstr_fd("smbash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	if (i == 1)
		ft_putendl_fd(MSGERR_DIR, 2);
	else if (i == 2)
		ft_putendl_fd(MSGERR_NOT_DIR, 2);
}

int	is_a_directory(char *str, int i)
{
	if (!str)
		return (0);
	if (str[0] && str[0] != '/')
		return (0);
	if (only_slash_in_str(str))
	{
		if (i)
			write_error_msg(str, 1);
		return (126);
	}
	else
	{
		if (i)
			write_error_msg(str, 2);
		return (127);
	}
	return (0);
}

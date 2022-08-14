/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd_loop_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:37:41 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 08:28:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pwd_loop_arg(char **str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = do_pwd_check_str(str[i]);
		if (res)
			return (res);
		i++;
	}
	return (0);
}

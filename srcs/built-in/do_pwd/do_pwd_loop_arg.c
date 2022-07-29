/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd_loop_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:37:41 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/28 17:41:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pwd_loop_arg(t_ulist **envp, char **str)
{
	t_ulist	*obj;
	int		i;
	int		res;

	obj = NULL;
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

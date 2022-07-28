/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset_update_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:15:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/28 14:42:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_unset_update_lst(t_ulist **envp, char **str)
{
	t_ulist	*obj;
	int		i;
	int		res;

	obj = NULL;
	i = 0;
	res = 0;
	while (str[i])
	{
		if (do_unset_check_str(str[i]) == 0)
		{
			obj = do_export_check_exist(envp, str[i], -1);
			if (obj)
			{
				if (ft_lst_delbyobj(obj, &env_free) == NULL)
					res++;
			}
		}
		else
			res++;
		i++;
	}
	if (res)
		return (EXIT_FAILURE);
	return (0);
}

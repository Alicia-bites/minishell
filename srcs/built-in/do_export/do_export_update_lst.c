/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_update_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:31:22 by antho             #+#    #+#             */
/*   Updated: 2022/07/28 19:03:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* use cases:
 * export NAME1		==> Add the variable but with NULL address on the value
 * env NAME1=value
 * env NAME1=value NAME2=value x=y
 */
int	do_export_update_lst(t_ulist **envp, char **str)
{
	t_ulist	*obj;
	int		i;
	int		sep_pos;
	int		res;

	obj = NULL;
	i = 0;
	sep_pos = -1;
	res = 0;
	while (str[i])
	{
		sep_pos = ft_index((const char *)str[i], ENV_SEP);
		if (do_export_check_str(str[i], sep_pos) == 0)
		{
			obj = do_export_check_exist(envp, str[i], sep_pos);
			if (obj)
			{
				if (do_export_update_env(obj, str[i], sep_pos) != 0)
					res++;
			}
			else
				do_export_create_env(envp, str[i]);
		}
		else
			res++;
		i++;
	}
	return (res);
}

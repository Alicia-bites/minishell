/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset_update_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:15:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 13:19:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_unset_update_lst(t_ulist **envp, char **str)
{
	t_ulist	*obj;
	int		i;
	int		sep_pos;

	obj = NULL;
	i = 0;
	sep_pos = -1;
	while (str[i])
	{
		if (do_unset_check_str(str[i]) == 0)
		{
			sep_pos = ft_index((const char *)str[i], ENV_SEP);
			obj = do_export_check_exist(envp, str[i], sep_pos);
			if (obj)
			{
				if (ft_lst_delbyobj(obj, &env_free) == NULL)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

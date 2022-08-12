/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_update_lst_do.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:41:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 14:58:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export_update_lst_do(t_ulist **env_lst, t_ulist *obj, char *str,
		int sep_pos)
{
	int	res;

	res = 0;
	if (obj)
	{
		if (do_export_update_env(obj, str, sep_pos) != 0)
			res = 1;
	}
	else if (do_export_create_env(env_lst, str) != 0)
			res = 1;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set_env_i_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:19:23 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 14:07:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_set_env_i_value(t_ulist **env_lst,
		char *env_key, char *env_value)
{
	t_ulist	*obj;

	obj = NULL;
	obj = do_export_check_exist(env_lst, env_key, -1);
	if (env_lst_set_env_i_update_lst(obj, env_value))
		return (EXIT_FAILURE);
	else
		return (0);
}

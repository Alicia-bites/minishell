/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_create_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:13:46 by antho             #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export_create_env(t_ulist **list, char *str)
{
	t_env	*env;

	env = NULL;
	env = env_init(str);
	if (!env)
		return (1);
	if (!ft_lst_append(list, (void *)env))
	{
		env_free((void *)env);
		return (ft_panic(-1, __func__, ERR_LST_APPEND));
	}
	return (0);
}

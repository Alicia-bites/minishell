/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_create_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:13:46 by antho             #+#    #+#             */
/*   Updated: 2022/07/20 13:55:41 by abarrier         ###   ########.fr       */
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
		return (ft_panic(-1, __FILE__, ERR_LST_APPEND));
	}
	return (0);
}

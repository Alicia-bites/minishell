/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env_create_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:13:46 by antho             #+#    #+#             */
/*   Updated: 2022/07/01 17:18:44 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_env_create_env(t_ulist **list, char *str)
{
	t_env	*env;

	env = env_init(str);
	if (!env)
		return (1);
	if (!ft_lst_append(list, (void *)env))
	{
		env_free((void *)env);
		ft_panic(-1, ERR_LST_APPEND);
		return (2);
	}
	return (0);
}

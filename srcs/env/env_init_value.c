/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:26:17 by antho             #+#    #+#             */
/*   Updated: 2022/07/15 14:29:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_init_value(t_env *env)
{
	int		sep_pos;

	sep_pos = ft_index((const char *)env->fullname, ENV_SEP);
	if (sep_pos < 0)
		env->value = NULL;
	else
	{
		env->value = ft_strdup(&env->fullname[sep_pos + 1]);
		if (!env->value)
		{
			ft_panic(-1, ERR_MALLOC);
			return (1);
		}
	}
	return (0);
}

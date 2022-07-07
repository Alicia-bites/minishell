/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:26:17 by antho             #+#    #+#             */
/*   Updated: 2022/06/28 19:58:51 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_init_value(t_env *env)
{
	int		sep_pos;

	sep_pos = ft_index((const char *)env->fullname, ENV_SEP);
	if (sep_pos < 0)
	{
		ft_panic(-1, "ERROR TO BE DEFINED");
		return (NULL);
	}
	env->value = &env->fullname[sep_pos + 1];
	return (env->value);
}

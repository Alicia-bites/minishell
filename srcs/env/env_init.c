/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:29:38 by antho             #+#    #+#             */
/*   Updated: 2022/07/18 08:55:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_init(char *env_fullname)
{
	t_env	*env;

	env = NULL;
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
	{
		ft_panic(-1, ERR_MALLOC);
		return (NULL);
	}
	env->key = NULL;
	env->value = NULL;
	if (!env_init_key(env, env_fullname))
	{
		free(env);
		return (NULL);
	}
	if (env_init_value(env, env_fullname) != 0)
	{
		free(env->key);
		free(env);
		return (NULL);
	}
	env->var_view = env_init_var_view(env);
	return (env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:29:38 by antho             #+#    #+#             */
/*   Updated: 2022/06/28 20:02:13 by antho            ###   ########.fr       */
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
	env->fullname = env_fullname;
	env->key = NULL;
	env->value = NULL;
	env->old_fullname = NULL;
	env->old_value = NULL;
	env->is_new = 0;
	if (!env_init_key(env, env_fullname))
	{
		free(env);
		return (NULL);
	}
	if (!env_init_value(env))
	{
		free(env->key);
		free(env);
		return (NULL);
	}
	return (env);
}

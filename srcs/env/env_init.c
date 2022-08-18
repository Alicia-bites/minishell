/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:29:38 by antho             #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * malloc t_env and init its property to NULL first, then to the expected 
 * value
 *
 * @PROPERTY:
 * env->key: key of the env node
 * example: 'USER'
 * env->value: value of the env node
 * example: 'smbash'
 * env->var_view: value to define the visibility of the property when using
 * env or export functions
 * example:
 * VAR_ALL = visible for env and export functions
 * VAR_ENV = only visible for env function
 * VAR_EXP = only visible for export function
 *
 * @PARAM:
 * char *env_fullname: environment string including the key and the value
 * example:
 * USER=smbash
 *
 * @RETURN:
 * !NULL: address of the newly created env node
 * NULL: error
 */
t_env	*env_init(char *env_fullname)
{
	t_env	*env;

	env = NULL;
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
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

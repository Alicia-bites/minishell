/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set_env_i_update_lst.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:53:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:02:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_set_env_i_update_lst(t_ulist *obj, char *str)
{
	t_env	*env;

	env = (t_env *)obj->content;
	if (env->value)
		free(env->value);
	env->value = ft_strdup(str);
	if (env->value)
	{
//		if (strcmp(env->key, ENV_PATH_NAME) == 0) // TO VALIDATE WITH EXPORT
//			env->var_view = VAR_ENV_I;
//		else
			env->var_view = VAR_ALL;
	}
	else
		return (ft_panic(-1, __FILE__, ERR_MALLOC));
	return (0);
}

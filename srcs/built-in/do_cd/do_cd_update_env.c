/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_update_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:45:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_update_env(t_ulist *obj, char *path)
{
	t_env	*env;

	env = (t_env *)obj->content;
	if (env->value)
		free(env->value);
	if (!path)
		return (1);
	env->value = ft_strdup(path);
	if (env->value)
		env->var_view = VAR_ALL;
	else
		return (ft_panic(-1, __func__, ERR_MALLOC));
	return (0);
}

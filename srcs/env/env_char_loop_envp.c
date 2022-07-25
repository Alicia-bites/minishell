/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_loop_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:17:51 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/25 19:22:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_char_loop_envp(t_ulist *obj, size_t len_envp, char **ptr)
{
	t_env	*env;
	int		i;

	env = NULL;
	i = 0;
	while (obj)
	{
		env = (t_env *)obj->content;
		if (env->var_view == VAR_ALL || env->var_view == VAR_EXP)
		{
			if (env_char_env(env, ptr, i))
				return (1);
			i++;
		}
		obj = obj->next;
	}
	return (0);
}

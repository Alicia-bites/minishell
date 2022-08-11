/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_loop_env_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:17:51 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 22:52:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * loop through every env node to create a env string and populate the envp
 * at a specific index
 *
 * @PARAM:
 * t_ulist *obj: minishell environment list node
 * char **envp: new env lst to be used for execve
 *
 * @RETURN:
 * 0: ok
 * > 0: error
 */
int	env_char_loop_env_lst(t_ulist *obj, char **envp)
{
	t_env	*env;
	int		i;

	env = NULL;
	i = 0;
	while (obj)
	{
		env = NULL;
		env = (t_env *)obj->content;
		if (env->var_view == VAR_ALL || env->var_view == VAR_ENV)
		{
			if (env_char_env(env, envp, i))
				return (1);
			i++;
		}
		obj = obj->next;
	}
	return (0);
}

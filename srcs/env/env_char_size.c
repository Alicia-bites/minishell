/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:21:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 23:01:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * define the minishell environment list size according to env node which
 * have visibility var_view VAR_ALL or VAR_EN
 *
 * @PARAM:
 * t_ulist **env_lst: minishell environment list
 *
 * @RETURN:
 * 0: ok
 * > 0: error
 */
size_t	env_char_size(t_ulist **env_lst)
{
	t_ulist	*obj;
	t_env	*env;
	size_t	res;

	obj = *env_lst;
	env = NULL;
	res = 0;
	while (obj)
	{
		env = (t_env *)obj->content;
		if (env->var_view == VAR_ALL || env->var_view == VAR_ENV)
			res++;
		obj = obj->next;
	}
	return (res);
}

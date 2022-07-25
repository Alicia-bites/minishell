/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:21:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/25 19:06:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	env_char_size(t_ulist **envp)
{
	t_ulist	*obj;
	t_env	*env;
	size_t	res;

	obj = *envp;
	env = NULL;
	res = 0;
	while (obj)
	{
		env = (t_env *)obj->content;
		if (env->var_view == VAR_ALL || env->var_view == VAR_EXP)
			res++;
		obj = obj->next;
	}
	return (res);
}

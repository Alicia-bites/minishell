/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:49:59 by antho             #+#    #+#             */
/*   Updated: 2022/07/15 13:23:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_env_show(void *content)
{
	t_env	*env;

	if (!content)
		return ;
	env = (t_env *)content;
	if (env->var_view == VAR_ALL || env->var_view == VAR_ENV
			|| env->value)
		printf("%s=%s\n", env->key, env->value);
}

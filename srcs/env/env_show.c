/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:39:13 by antho             #+#    #+#             */
/*   Updated: 2022/06/28 19:59:55 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_show(void *content)
{
	t_env	*env;

	if (!content)
		return ;
	env = (t_env *)content;
	printf("fullname: %s\n", env->fullname);
	if (env->key)
		printf("key: %s\n", env->key);
	if (env->value)
		printf("value: %s\n", env->value);
	if (env->old_fullname)
		printf("old fullname: %s\n", env->old_fullname);
	if (env->old_value)
		printf("old value: %s\n", env->old_value);
	printf("is_new: %d\n", env->is_new);
	printf("%s\n", SEP_P);
}
